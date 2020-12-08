//
// Created by Wycer on 2020/12/8.
//

#pragma once

#include "exp.h"
#include "stmt.hpp"
#include "comp_st.h"

struct Stmt {
    Exp *exp;
    Stmt *stmt;
    CompSt *compSt;

    Stmt(Node *node, Type *ret_type) {
        auto c = node->children;
        if (node->type == NodeType::StmtExp) {
            exp = new Exp(c[0]);
        }
        if (node->type == NodeType::StmtCompSt) {
            compSt = new CompSt(c[0], ret_type);
        }
        if (node->type == NodeType::StmtReturn) {
            Field *ret = (new Exp(c[1]))->expression->field;
            if (!ret->type->equals(ret_type))
                semantic_error(ErrorType::SemanticType8, node->lineno, "");
        }
        if (node->type == NodeType::StmtIf) {
            exp = new Exp(c[2]);
            stmt = new Stmt(c[4], ret_type);
        }
        if (node->type == NodeType::StmtIfElse) {
            exp = new Exp(c[2]);
            new Stmt(c[4], ret_type);
            new Stmt(c[6], ret_type);
        }
        if (node->type == NodeType::StmtWhile) {
            new Exp(c[2]);
            new Stmt(c[4], ret_type);
        }
    }
};