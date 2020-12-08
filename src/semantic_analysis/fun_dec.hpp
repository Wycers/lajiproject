//
// Created by Wycer on 2020/12/8.
//

#pragma once

#include "base.hpp"

#include "var_list.hpp"

struct FunDec {
    Func *func;
    VarList *varList;

    FunDec(Node *node, Type *ret_type) {
        std::string name = id(node->children[0]);
        auto param_list = std::vector<Field *>();
        if (node->type == NodeType::FunDecArgs) {
            varList = new VarList(node->children[2]);
            param_list = varList->fields;
            for (auto param : param_list)
                _type_exist(param->type, param->lineno);
        }
        func = new Func{name, param_list, ret_type};
    }

};