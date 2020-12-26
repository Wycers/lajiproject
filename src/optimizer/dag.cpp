//
// Created by Wycer on 2020/12/25.
//

#include "dag.h"

#include <fstream>
#include <unordered_map>

#define INNER_DCE
//#define INNER_CP
#define INNER_CSE
#define INNER_CE

using std::cout, std::endl;

IRList &operator+=(IRList &a, const IRList b);

IRList &operator+=(IRList &a, IR *b);

DagNode *bubble(DagNode *curNode) {
    while (curNode->ir && curNode->ir->irType == IRType::IR_ASSIGN) {
        curNode = curNode->children[0];
    }
    return curNode;
}

DAG::DAG(IRList irs) {
    nodes.clear();

    cout << "DAG" << endl;
    for (auto ir : irs) {
        auto curNode = new DagNode();
        cout << ir->str() << endl;
        switch (ir->irType) {
            case IRType::IR_DEC: {
                curNode->info = "DEC";
                curNode->ir = ir;

                auto node0 = getNode(ir->args[0]);
                curNode->children.push_back(node0);
                addNode(ir->args[0], curNode);
            }
                break;
            case IRType::IR_CALL: {
                curNode->info = "CALL";
                curNode->ir = ir;

//                auto node1 = getNode(ir->args[1]);
//                curNode->children.push_back(node1);
                addNode(ir->args[0], curNode);
            }
                break;
            case IRType::IR_ASSIGN: {

                curNode->info = "ASSIGN";
                curNode->ir = ir;

                auto node1 = getNode(ir->args[1]);
#ifdef INNER_CP
                node1 = bubble(node1);
#endif
                if (node1->ir != nullptr && (
                        node1->ir->irType == IRType::IR_ADD ||
                        node1->ir->irType == IRType::IR_SUB ||
                        node1->ir->irType == IRType::IR_MUL ||
                        node1->ir->irType == IRType::IR_DIV
                )) {
                    if (node1->ir->irType == IRType::IR_ADD) {
                        curNode->ir = new ADD_IR(node1->ir->args);
                    }
                    if (node1->ir->irType == IRType::IR_SUB) {
                        curNode->ir = new SUB_IR(node1->ir->args);
                    }
                    if (node1->ir->irType == IRType::IR_MUL) {
                        curNode->ir = new MUL_IR(node1->ir->args);
                    }
                    if (node1->ir->irType == IRType::IR_DIV) {
                        curNode->ir = new DIV_IR(node1->ir->args);
                    }
                    curNode->ir->args[0] = ir->args[0];
                    curNode->children.clear();
                    curNode->children.push_back(node1->children[0]);
                    curNode->children.push_back(node1->children[1]);
                } else {
                    curNode->children.push_back(node1);
                }
                addNode(ir->args[0], curNode);
            }
                break;
            case IRType::IR_REF: {
                curNode->info = "Address Of";
                curNode->ir = ir;

                auto node1 = getNode(ir->args[1]);
                curNode->children.push_back(node1);
                addNode(ir->args[0], curNode);
                break;
            }
            case IRType::IR_LDEREF: {
                curNode->info = "Set To";
                curNode->ir = ir;

                auto node1 = getNode(ir->args[1]);
                curNode->children.push_back(node1);
                addNode(ir->args[0], curNode);
                break;
            }
            case IRType::IR_RDEREF: {
                curNode->info = "Set from";
                curNode->ir = ir;

                auto node1 = getNode(ir->args[1]);
                curNode->children.push_back(node1);
                addNode(ir->args[0], curNode);
                break;
            }
            case IRType::IR_ADD:
            case IRType::IR_SUB:
            case IRType::IR_MUL:
            case IRType::IR_DIV: {
                DagNode *cnodes[2] = {getNode(ir->args[1]), getNode(ir->args[2])};
#ifdef INNER_CP
                cnodes[0] = bubble(cnodes[0]);
                cnodes[1] = bubble(cnodes[1]);
#endif
                curNode->children.push_back(cnodes[0]);
                curNode->children.push_back(cnodes[1]);
                curNode->ir = ir;
#ifdef INNER_CSE
                DagNode *target = nullptr;
                for (auto i = nodes.rbegin(); i != nodes.rend(); ++i) {
                    auto node = *i;
                    if (node->ir == nullptr || node->ir->irType != ir->irType)
                        continue;
                    if (node->children[0] == cnodes[0] && node->children[1] == cnodes[1]) {
                        target = node;
                        break;
                    }
                }
                if (target != nullptr) {
                    curNode->children.clear();
                    curNode->children.push_back(target->children[0]);
                    curNode->children.push_back(target->children[1]);
                }
#endif
#ifdef INNER_CE
                if (curNode->ir->irType != IRType::IR_ASSIGN) {
                    if (cnodes[0]->name[0] == '#' && cnodes[1]->name[0] == '#') {
                        int a = std::stoi(cnodes[0]->name.substr(1));
                        int b = std::stoi(cnodes[1]->name.substr(1));
                        int res = 0;
                        switch (curNode->ir->irType) {
                            case IRType::IR_ADD:
                                res = a + b;
                                break;
                            case IRType::IR_SUB:
                                res = a - b;
                                break;
                            case IRType::IR_MUL:
                                res = a * b;
                                break;
                            case IRType::IR_DIV:
                                res = a / b;
                                break;
                            default:
                                break;
                        }
                        auto nodeX = getNode("#" + std::to_string(res));

                        curNode->ir = new ASSIGN_IR({ir->args[0], nodeX->name});
                        curNode->children.clear();
                        curNode->children.push_back(nodeX);
                    } else {
                        DagNode *nodeX = aoNode(ir, cnodes);
                        if (nodeX != nullptr) {
                            curNode->ir = new ASSIGN_IR({ir->args[0], nodeX->name});
                            curNode->children.clear();
                            curNode->children.push_back(nodeX);
                        }
                    }
                }
#endif
                addNode(ir->args[0], curNode);
            }
                break;
            case IRType::IR_RET: {
                curNode->info = "RET";
                curNode->ir = ir;

                auto node0 = getNode(ir->args[0]);
#ifdef INNER_CP
                node0 = bubble(node0);
#endif
                curNode->children.push_back(node0);
                addNode("RETURN", curNode);
            }
                break;
            case IRType::IR_READ: {
                curNode->ir = ir;
                curNode->info = "READ";
                addNode(ir->args[0], curNode);
            }
                break;
            case IRType::IR_ARG: {
                curNode->info = "ARG";
                curNode->ir = ir;
                auto node0 = getNode(ir->args[0]);
#ifdef INNER_CP
                node0 = bubble(node0);
#endif
                curNode->children.push_back(node0);
                addNode("ARG", curNode);
            }
                break;
            case IRType::IR_WRITE: {
                curNode->info = "WRITE";
                curNode->ir = ir;

                auto node0 = getNode(ir->args[0]);
#ifdef INNER_CP
                node0 = bubble(node0);
#endif
                curNode->children.push_back(node0);
                addNode("WRITE", curNode);
            }
                break;
            case IRType::IR_IF: {
                auto node1 = getNode(ir->args[0]);
                auto node2 = getNode(ir->args[2]);
#ifdef INNER_CP
                node1 = bubble(node1);
                node2 = bubble(node2);
#endif
                curNode->children.push_back(node1);
                curNode->children.push_back(node2);
                curNode->ir = ir;
                addNode("IF: " + ir->args[1], curNode);
            }
                break;
            case IRType::IR_FUNCTION:
            case IRType::IR_PARAM:
            case IRType::IR_LABEL:
            case IRType::IR_GOTO: {
                curNode->ir = ir;
                nodes.push_back(curNode);
            }
                break;
        }
    }
    cout << endl;
}

IRList DAG::restore() {
    IRList irs;
    irs.clear();

    for (auto node : nodes) {
        if (node->live == false)
            continue;

        if (node->ir == nullptr) {
            continue;
        }

        irs += node->ir;
    }

    return irs;
}

void DAG::print(std::string filename) {
    std::ofstream out;
    out.open("/home/wycer/test_env/DAG_" + filename + ".gv");

    out << "digraph {" << endl;

    for (auto node : nodes) {
        for (auto child:node->children) {
            if (child->name[0] != '#')
                continue;
            out << std::to_string(child->id) << " [label=\" NUM:" << child->name.substr(1) << "\"]" << endl;
        }
    }
    for (auto node : nodes) {
        if (node->live == false)
            continue;
        cout << "name:" << node->name << endl;

        out << std::to_string(node->id) << " [label=\" "
            << (node->name[0] == '#' ? node->name.substr(1) : node->name) << endl;
        if (node->ir != nullptr) {
            switch (node->ir->irType) {
                case IRType::IR_ADD:
                    node->info = "ADD";
                    break;
                case IRType::IR_SUB:
                    node->info = "SUB";
                    break;
                case IRType::IR_MUL:
                    node->info = "MUL";
                    break;
                case IRType::IR_DIV:
                    node->info = "DIV";
                    break;
                case IRType::IR_RET:
                    node->info = "RETURN";
                    break;
                case IRType::IR_ASSIGN:
                    node->info = "ASSIGN";
                    break;
                case IRType::IR_REF:
                    node->info = "Address Of";
                    break;
            }
        }
        out << node->info << endl;
        out << "\"]" << endl;

        for (auto child : node->children) {
            out << std::to_string(child->id) << " -> " << std::to_string(node->id) << endl;
        }

        out << endl;
    }

    out << "}" << endl;
}


void DAG::addNode(std::string name, DagNode *node) {
    mp[name] = node;
    node->name = name;
    node->id = ++cnt;


    switch (node->ir->irType) {
        case IRType::IR_IF:
            node->ir->args[0] = node->children[0]->name;
            node->ir->args[2] = node->children[1]->name;
            break;
        case IRType::IR_ADD:
        case IRType::IR_SUB:
        case IRType::IR_MUL:
        case IRType::IR_DIV:
            node->ir->args[0] = node->name;
            node->ir->args[1] = node->children[0]->name;
            node->ir->args[2] = node->children[1]->name;
            break;
        case IRType::IR_ASSIGN:
            node->ir->args[1] = node->children[0]->name;
            break;
        case IRType::IR_RET:
        case IRType::IR_WRITE:
        case IRType::IR_ARG:
            node->ir->args[0] = node->children[0]->name;
            break;
    }

    nodes.push_back(node);
}

DagNode *DAG::getNode(std::string name) {
    auto p = mp.find(name);
    if (p != mp.end()) {
        auto curNode = p->second;
        return curNode;
    }
    DagNode *node = new DagNode();

    node->name = name;
    node->id = ++cnt;
    node->info = name.substr(1);
    node->ir = nullptr;
    mp[name] = node;
    return node;
}

void DAG::optimize() {

#ifdef INNER_CE
    for (auto node : nodes) {
        if (node->live == false)
            continue;
        if (node->ir->irType == IRType::IR_ASSIGN) {
            cout << node->ir->str() << endl;
            if (node->ir->args[0] == node->ir->args[1]) {
                node->live = false;
            }
        }
    }
#endif
#ifdef INNER_DCE
    std::unordered_map<DagNode *, bool> out;
    bool effect = true;
    while (effect) {
        effect = false;
        out.clear();
        for (auto node: nodes) {
            if (node->live == false)
                continue;
            cout << node->name << endl;
            for (auto child : node->children) {
                cout << child->name << endl;
                out[child] = true;
            }
            cout << endl;
        }
        for (auto node : nodes) {
            if (node->live == false)
                continue;
            cout << "qwq:" << node->name << endl;
            if (node->name.rfind("v_", 0) == 0) {
                continue;
            }

            switch (node->ir->irType) {
                case IRType::IR_ADD:
                case IRType::IR_SUB:
                case IRType::IR_MUL:
                case IRType::IR_DIV:
                case IRType::IR_ASSIGN:
                case IRType::IR_REF:
                    if (out.find(node) == out.end()) {
                        node->live = false;
                        effect = true;
                    }
                default:
                    continue;
            }

        }
    }
#endif
}

DagNode *DAG::aoNode(IR *ir, DagNode **cnodes) {
    int cursor = -1, n = 0;
    if (cnodes[0]->name[0] == '#') {
        cursor = 0;
        n = std::stoi(cnodes[0]->name.substr(1));
    }
    if (cnodes[1]->name[0] == '#') {
        cursor = 1;
        n = std::stoi(cnodes[1]->name.substr(1));
    }

    if (cursor == -1)
        return nullptr;
    DagNode *nodeX = nullptr;

    cout << "OMG:" << n << endl;
    int res = 0;
    switch (ir->irType) {
        case IRType::IR_ADD:
            if (n == 0) {
                nodeX = cnodes[cursor ^ 1];
            }
            break;
        case IRType::IR_SUB:
            if (n == 0 && cursor == 1) {
                nodeX = cnodes[cursor ^ 1];
            }
            break;
        case IRType::IR_MUL:
            if (n == 0) {
                nodeX = cnodes[cursor];
            }
            if (n == 1) {
                nodeX = cnodes[cursor ^ 1];
            }
            break;
        case IRType::IR_DIV:
            if (n == 0 && cursor == 0) {
                nodeX = cnodes[cursor];
            }
            if (n == 1 && cursor == 1) {
                nodeX = cnodes[cursor ^ 1];
            }
            break;
        default:
            break;
    }

    if (nodeX != nullptr) {
        return nodeX;
    }

    DagNode *tmp = cnodes[cursor ^ 1];
    if (tmp->ir == nullptr)
        return nullptr;
    switch (tmp->ir->irType) {
        case IRType::IR_ADD:
        case IRType::IR_SUB:
        case IRType::IR_MUL:
        case IRType::IR_DIV:
            break;
        default:
            return nullptr;
    }

    int tp1 = (ir->irType == IRType::IR_ADD || ir->irType == IRType::IR_SUB) ? 1 : 0;
    int tp2 = (tmp->ir->irType == IRType::IR_ADD || tmp->ir->irType == IRType::IR_SUB) ? 1 : 0;

    if (tp1 != tp2)
        return nullptr;


    DagNode *tmp_cnodes[2] = {tmp->children[0], tmp->children[1]};
    int tmp_cursor = -1, m = 0;
    if (tmp_cnodes[0]->name[0] == '#') {
        tmp_cursor = 0;
        m = std::stoi(tmp_cnodes[0]->name.substr(1));
    }
    if (tmp_cnodes[1]->name[0] == '#') {
        tmp_cursor = 1;
        m = std::stoi(tmp_cnodes[1]->name.substr(1));
    }
    if (tmp_cursor == -1) {
        return nullptr;
    }
    IR *finalIr = nullptr;
    DagNode *node1 = nullptr, *node2 = nullptr;
    cout << "nmdasdasdad " << n << " " << m << endl;
    if (cursor == 0) {
        // n x (a x b)
        if (tmp_cursor == 0) {
            // n x (m x b)
            switch (ir->irType) {
                case IRType::IR_ADD:
                    // n + (m x b)
                    if (tmp->ir->irType == IRType::IR_ADD) {
                        // n + (m + b)
                        node1 = getNode("#" + std::to_string(n + m));
                        node2 = tmp_cnodes[tmp_cursor ^ 1];
                        finalIr = new ADD_IR({});
                    } else {
                        // n + (m - b)
                        node1 = getNode("#" + std::to_string(n + m));
                        node2 = tmp_cnodes[tmp_cursor ^ 1];
                        finalIr = new SUB_IR({});
                    }
                    break;
                case IRType::IR_SUB:
                    // n - (m x b)
                    if (tmp->ir->irType == IRType::IR_ADD) {
                        // n - (m + b)
//                        node1 = getNode("#" + std::to_string(n - m));
//                        node2 = tmp_cnodes[tmp_cursor ^ 1];
//                        finalIr = new ADD_IR({});

                        return nullptr;
                    } else {
                        // n - (m - b)
                        if (n - m >= 0) {
                            node1 = getNode("#" + std::to_string(n - m));
                            node2 = tmp_cnodes[tmp_cursor ^ 1];
                            finalIr = new ADD_IR({});
                        } else {
                            return nullptr;
                        }
                    }
                    break;
                case IRType::IR_MUL:
                    // n * (m x b)

                    break;
                case IRType::IR_DIV:
                    // n / (m x b)
                    break;
            }
        } else {
            // n x (a x m)
            switch (ir->irType) {
                case IRType::IR_ADD:
                    // n + (a x m)

                    break;
                case IRType::IR_SUB:
                    // n x (a x m)

                    break;
                case IRType::IR_MUL:
                    // n x (a x m)

                    break;
                case IRType::IR_DIV:
                    // n x (a x m)
                    break;
            }
        }
    } else {
        // (a x b) x n
        if (tmp_cursor == 0) {
            // (m x b) x n
            switch (ir->irType) {
                case IRType::IR_ADD:
                    // (m x b) + n

                    break;
                case IRType::IR_SUB:
                    // (m x b) - n

                    break;
                case IRType::IR_MUL:
                    // (m x b) * n

                    break;
                case IRType::IR_DIV:
                    // (m x b) / n
                    break;
            }

        } else {
            // (a x m) x n
            switch (ir->irType) {
                case IRType::IR_ADD:
                    // (a x m) + n

                    break;
                case IRType::IR_SUB:
                    // (a x m) - n

                    break;
                case IRType::IR_MUL:
                    // (a x m) * n

                    break;
                case IRType::IR_DIV:
                    // (a x m) / n
                    break;
            }

        }

    }


//    DagNode *fuck = new DagNode();
//    finalIr->args = std::string();
//    fuck->ir = finalIr;
//    fuck->children.clear();
//    fuck->children.push_back(node1);
//    fuck->children.push_back(node2);

    return nullptr;

}

DagNode::DagNode() {
}
