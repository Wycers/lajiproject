//
// Created by Wycer on 2020/12/24.
//

#include "cfg.h"
#include <fstream>

using std::cout, std::endl;

void CFG::clear() {
    edges.clear();
    blocks.clear();
    label_map.clear();
}

Edge *CFG::addEdge(Block *a, Block *b) {
    cout << a->str() << "==========>" << b->str() << endl;
    auto edge = new Edge{
            b->idx,
            a->head
    };
    edges.push_back(edge);
    a->head = edges.size() - 1;
    return edge;
}

CFG::CFG(IRList irs) {
    this->clear();

    for (auto ir : irs) {
        cout << ir->str() << endl;
    }
    cout << endl;

    name = irs.front()->args[0];

    auto last = irs.begin();
    Block *lastBlock = nullptr;
    for (auto i = irs.begin(); i != irs.end(); ++i) {
        auto ir = *i;
        Block *block = nullptr;

        if (typeid(*ir) == typeid(LABEL_IR)) {
            IRList tmp = std::vector<IR *>(last, i);
            last = i;
            block = addBlock(tmp);
        }
        if (typeid(*ir) == typeid(IF_IR)) {
            IRList tmp = std::vector<IR *>(last, i + 1);
            last = i + 1;
            block = addBlock(tmp);
        }
        if (typeid(*ir) == typeid(GOTO_IR)) {
            IRList tmp = std::vector<IR *>(last, i + 1);
            last = i + 1;
            block = addBlock(tmp);
        }
        if (i + 1 == irs.end()) {
            IRList tmp = std::vector<IR *>(last, irs.end());
            block = addBlock(tmp);
        }
        if (block == nullptr)
            continue;

        if (lastBlock != nullptr && typeid(*(lastBlock->irs.back())) != typeid(GOTO_IR)) {
            addEdge(lastBlock, block);
        }
        lastBlock = block;
    }

    for (auto block : blocks) {
        cout << "back: " << block->irs.back()->str() << endl;
        auto lastIR = block->irs.back();
        std::string target;
        if (typeid(*lastIR) == typeid(GOTO_IR)) {
            target = lastIR->args[0];
        }
        if (typeid(*lastIR) == typeid(IF_IR)) {
            target = lastIR->args[3];
        }

        if (target.empty())
            continue;

        auto p = label_map.find(target);
        cout << "try to find label: ==>" << target << endl;
        if (p != label_map.end()) {
            addEdge(block, p->second);
        } else {
            cout << "??" << endl;
        }
    }

}

void CFG::print(std::string filename) {
    std::ofstream out;
    out.open("/home/wycer/test_env/CFG_" + filename + ".gv");

    out << "digraph {" << endl;

    for (auto block : blocks) {
        out << block->str() << "[label=\"" << block->str() << endl;

        for (auto ir : block->irs) {
            out << ir->str() << endl;
        }

        out << "\"]" << endl;

        for (auto i = block->head; i != -1; i = edges[i]->next) {
            auto edge = edges[i];
            auto v = blocks[edge->to];
            out << block->str() << " -> " << v->str() << endl;
        }
    }

    out << "}" << endl;
}

Block *CFG::addBlock(IRList irs) {
    if (irs.empty())
        return nullptr;

    auto block = new Block(irs);

    auto first_ir = irs.front();
    if (typeid(*first_ir) == typeid(LABEL_IR)) {
        cout << "add: " << first_ir->args[0] << endl;
        label_map[first_ir->args[0]] = block;
    }

    block->idx = blocks.size();
    block->head = -1;
    block->irs = irs;

    blocks.push_back(block);
    cout << "===> New block" << endl;
    for (auto ir: irs) {
        cout << ir->str() << endl;
    }
    cout << endl;

    return block;
}

std::string CFG::str() {
    return name;
}

void CFG::optimize() {
    for (auto block : blocks) {
        block->optimize();
    }
}

void Block::optimize() {
    this->dag = new DAG(irs);
    this->dag->print(this->str());
}

Block::Block(IRList irs) {
    this->irs = irs;
}

std::string Block::str() {
    return "block_" + std::to_string(this->idx);
}
