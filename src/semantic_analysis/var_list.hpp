//
// Created by Wycer on 2020/12/8.
//

#pragma once

#include "param_dec.hpp"
#include "var_list.hpp"

struct VarList {
    std::vector<Field *> fields;
    ParamDec *paramDec;
    VarList *varList;

    VarList(Node *node) {
        paramDec = new ParamDec(node->children[0]);
        Field *field = paramDec->field;
        fields = std::vector<Field *>{field};
        if (node->type == NodeType::VarList) {
            varList = new VarList(node->children[2]);
            auto tail = varList->fields;
            fields.insert(fields.end(), tail.begin(), tail.end());
        }
    }
};