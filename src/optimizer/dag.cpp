//
// Created by Wycer on 2020/12/25.
//

#include "dag.h"

#include <fstream>
#include <unordered_map>

#define DeadCodeElimination
#define UselessAssign
#define AssignBeforeExp

using std::cout, std::endl;

IRList &operator+=(IRList &a, const IRList b);

IRList &operator+=(IRList &a, IR *b);

DAG::DAG(IRList irs) {
    nodes.clear();

    cout << "DAG" << endl;
    for (auto ir : irs) {
        auto curNode = new DagNode();
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
                curNode->children.push_back(node1);
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
                auto node1 = getNode(ir->args[1]);
                auto node2 = getNode(ir->args[2]);

                curNode->children.push_back(node1);
                curNode->children.push_back(node2);
                curNode->ir = ir;
                addNode(ir->args[0], curNode);
            }
                break;
            case IRType::IR_RET: {
                curNode->info = "RET";
                curNode->ir = ir;

                auto node0 = getNode(ir->args[0]);
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
            case IRType::IR_WRITE: {
                curNode->info = "WRITE";
                curNode->ir = ir;

                auto node0 = getNode(ir->args[0]);
                curNode->children.push_back(node0);
                addNode("WRITE", curNode);
            }
                break;
            case IRType::IR_IF: {
                auto node1 = getNode(ir->args[0]);
                auto node2 = getNode(ir->args[2]);

                curNode->children.push_back(node1);
                curNode->children.push_back(node2);
                curNode->ir = ir;
                addNode("IF: " + ir->args[1], curNode);
            }
                break;
            case IRType::IR_ARG:
            case IRType::IR_FUNCTION:
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

        auto c = node->children;
        IR *ir = nullptr;
        switch (node->ir->irType) {
            case IRType::IR_ADD:
            case IRType::IR_SUB:
            case IRType::IR_MUL:
            case IRType::IR_DIV:
                node->ir->args[0] = node->name;
                node->ir->args[1] = c[0]->name;
                node->ir->args[2] = c[1]->name;
                ir = node->ir;
                break;
            case IRType::IR_RET:
            case IRType::IR_WRITE:
                node->ir->args[0] = c[0]->name;
                ir = node->ir;
                break;
            default:
                ir = node->ir;
        }
        irs += ir;
    }
    return irs;
}

void DAG::print(std::string filename) {
    std::ofstream out;
    out.open("/home/wycer/test_env/DAG_" + filename + ".gv");

    out << "digraph {" << endl;

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
    nodes.push_back(node);
}

DagNode *DAG::getNode(std::string name) {
    auto p = mp.find(name);
    if (p != mp.end()) {
        return p->second;
    }
    DagNode *node = new DagNode();

    node->name = name;
    node->id = ++cnt;
    node->info = name.substr(1);
    mp[name] = node;
    return node;
}

void DAG::optimize() {
#ifdef DeadCodeElimination
    std::unordered_map<DagNode *, bool> out;
#endif
#ifdef UselessAssign
    for (auto node: nodes) {
        DagNode *curNode = node;
        while (curNode->ir && curNode->ir->irType == IRType::IR_ASSIGN) {
            curNode = curNode->children[0];
        }
        if (curNode == node)
            continue;
        node->children[0] = curNode;
    }
#endif
#ifdef AssignBeforeExp
    for (auto node: nodes) {
        DagNode *curNode = nullptr;
        switch (node->ir->irType) {
            case IRType::IR_ADD:
            case IRType::IR_SUB:
            case IRType::IR_MUL:
            case IRType::IR_DIV:
            case IRType::IR_IF:
                curNode = node->children[0];
                while (curNode->ir && curNode->ir->irType == IRType::IR_ASSIGN) {
                    curNode = curNode->children[0];
                }
                node->children[0] = curNode;
                curNode = node->children[1];
                while (curNode->ir && curNode->ir->irType == IRType::IR_ASSIGN) {
                    curNode = curNode->children[0];
                }
                node->children[1] = curNode;
                break;
            case IRType::IR_WRITE:
            case IRType::IR_RET:
                curNode = node->children[0];
                while (curNode->ir && curNode->ir->irType == IRType::IR_ASSIGN) {
                    curNode = curNode->children[0];
                }
                node->children[0] = curNode;
                break;
            default:
                continue;
        }
    }
#endif
#ifdef DeadCodeElimination
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

DagNode::DagNode() {
}
