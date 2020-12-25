//
// Created by Wycer on 2020/12/25.
//

#include "dag.h"

#include <fstream>

using std::cout, std::endl;

DAG::DAG(IRList irs) {
    nodes.clear();

    cout << "DAG" << endl;
    for (auto ir : irs) {
        DagNode *curNode = new DagNode();
        switch (ir->irType) {
            case IRType::IR_ASSIGN: {
                curNode->info = "ASSIGN";
                curNode->ir = ir;

                auto node1 = getNode(ir->args[1]);
                curNode->children.push_back(node1);
                addNode(ir->args[0], curNode);
                break;
            }
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

        }
    }
    cout << endl;
}

IRList DAG::restore() {
    return IRList();
}

void DAG::print(std::string filename) {
    std::ofstream out;
    out.open("/home/wycer/test_env/DAG_" + filename + ".gv");

    out << "digraph {" << endl;

    for (auto node : nodes) {
        if (node->name == "")
            continue;
        out << node->name << " [label=\" " << node->name << endl;
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
            out << child->name << " -> " << node->name << endl;
        }

        out << endl;
    }

    out << "}" << endl;
}


void DAG::addNode(std::string name, DagNode *node) {
    mp[name] = node;
    if (name[0] == '#')
        node->name = name.substr(1);
    else
        node->name = name + "_" + std::to_string(++cnt);
    nodes.push_back(node);
}

DagNode *DAG::getNode(std::string name) {
    auto p = mp.find(name);
    if (p != mp.end()) {
        return p->second;
    }
    DagNode *node = new DagNode();

    if (name[0] == '#')
        node->name = name.substr(1);
    else
        node->name = name + "_" + std::to_string(++cnt);
    node->info = name.substr(1);
    mp[name] = node;
    return node;
}

DagNode::DagNode() {
}
