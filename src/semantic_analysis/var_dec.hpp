//
// Created by Wycer on 2020/12/8.
//
#pragma once

#include <src/node/node.h>
#include <type.hpp>

int _int(Node *node) {
    return strtol(node->text, nullptr, 10);
}

struct VarDec {

    Field *field = nullptr;
    VarDec *nextVarDec = nullptr;

    VarDec(Node *node, Type *type) {
#ifdef debug
        printf("var_dec\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
        if (node->type == NodeType::VarDec)
            field = new Field{node->children[0]->text, type, node->lineno};

        if (node->type == NodeType::VarDecArray) {
            nextVarDec = new VarDec(node->children[0], new Type(new Array{type, _int(node->children[2])}));
            field = nextVarDec->field;
        }
    }
};
