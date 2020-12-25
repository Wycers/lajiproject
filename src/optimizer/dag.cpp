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
        switch (ir->irType) {
            case IRType::IR_ASSIGN: {
                auto node0 = getNode(ir->args[0]);
                node0->dst = ir->args[0];
                node0->name = "ASSIGN";
                if (ir->args[1][0] == '#') {
                    node0->name += " " + ir->args[1];
                } else {
                    auto node1 = getNode(ir->args[1]);

                    node1->dst = ir->args[1];
                    node1->name = "";
                    node0->children.push_back(node1);
                }
            }
                break;
            case IRType::IR_ADD:
            case IRType::IR_SUB:
            case IRType::IR_MUL:
            case IRType::IR_DIV:
                auto node0 = getNode(ir->args[0]);
                cout << ir->args[0] << endl;
                node0->dst = ir->args[0];
                node0->name = "ADD";

                auto node1 = getNode(ir->args[1]);
                auto node2 = getNode(ir->args[2]);

                cout << node1->dst << endl;
                cout << node2->dst << endl;

                node0->children.push_back(node1);
                node0->children.push_back(node2);
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


        out << node->dst << " [label=\" " << node->dst << endl;
        out << node->name << endl;
        out << "\"]" << endl;

        for (auto child : node->children) {
            out << child->dst << " -> " << node->dst << endl;
        }

        out << endl;
    }

    out << "}" << endl;
}

DagNode *DAG::getNode(std::string name) {
    auto p = mp.find(name);
    if (p != mp.end()) {
        return p->second;
    }
    DagNode *node = new DagNode();

    node->dst = "";
    node->name = "";

    nodes.push_back(node);
    return node;
}

DagNode::DagNode() {

}
