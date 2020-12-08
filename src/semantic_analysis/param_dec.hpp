//
// Created by Wycer on 2020/12/8.
//

#pragma once

#include "specifier.h"
#include "var_dec.hpp"

struct ParamDec {
    Specifier *specifier;
    VarDec *varDec;
    Field *field;
    ParamDec(Node *node) {
        specifier = new Specifier(node->children[0]);
        Type *type = specifier->type;
        varDec = new VarDec(node->children[1], type);
        field = varDec->field;
    }
};