//
// Created by Wycer on 2020/12/8.
//

#pragma once

#include "specifier.h"
#include "dec_list.h"

#include "base.hpp"

struct Def {

    Specifier *specifier;
    DecList *decList;

    std::vector<Field *> fields;

    Def(Node *node) {
#ifdef debug
        printf("def\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
    printf("%s\n", node->text);
#endif
        specifier = new Specifier(node->children[0]);
        Type *type = specifier->type;
        if (type == nullptr) {
            printf("fatal error");
            exit(-1);
        }
        Type *derived = _type_exist(type, node->lineno);
        if (derived == nullptr)
            decList = new DecList(node->children[1], type);
        else
            decList = new DecList(node->children[1], derived);
        fields = decList->fields;
    }
};
