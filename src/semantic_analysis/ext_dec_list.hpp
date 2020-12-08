//
// Created by Wycer on 2020/12/8.
//

#pragma once

#include "var_dec.hpp"

struct ExtDecList {

    VarDec *varDec;
    ExtDecList *extDecList;

    std::vector<Field *> fields;

    ExtDecList(Node *node, Type *type) {
#ifdef debug
        printf("ext_dec_list\n");
#endif
        varDec = new VarDec(node->children[0], type);
        Field *field = varDec->field;
        fields = std::vector<Field *>{field};
        if (node->type == NodeType::ExtDecListMultiple) {
            extDecList = new ExtDecList(node->children[2], type);
            auto tail = extDecList->fields;
            fields.insert(fields.end(), tail.begin(), tail.end());
        }
    }
};