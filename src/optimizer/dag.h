//
// Created by Wycer on 2020/12/25.
//

#pragma once


#include <unordered_map>
#include <ir.hpp>

struct DagNode {
    std::string dst, name;
    std::vector<DagNode *> children;

    DagNode();
};

struct DAG {

    std::vector<DagNode *> nodes;

    std::unordered_map<std::string, DagNode *> mp;

    DAG(IRList irs);

    IRList restore();

    DagNode *getNode(std::string name);

    void print(std::string filename);
};


