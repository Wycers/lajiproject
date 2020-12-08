//
// Created by Wycer on 2020/12/8.
//

#pragma once

#include "stmt.hpp"

struct StmtList {
    Stmt *stmt;
    StmtList *nextStmtList;

    StmtList(Node *node, Type *ret_type) {
        if (node && node->type == NodeType::StmtList) {
            stmt = new Stmt(node->children[0], ret_type);
            nextStmtList = new StmtList(node->children[1], ret_type);
        }
    }
};