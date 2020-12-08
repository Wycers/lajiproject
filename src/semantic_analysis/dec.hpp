//
// Created by Wycer on 2020/12/8.
//

#pragma once

#include <error.h>
#include "var_dec.hpp"
#include "exp.h"

struct Dec {

    Field *field = nullptr;

    VarDec *varDec = nullptr;

    Dec(Node *node, Type *type) {
#ifdef debug
        printf("dec\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
        varDec = new VarDec(node->children[0], type);
        Field *field = varDec->field;
        if (node->type == NodeType::DecWithAssign) {
            Field *e = (new Exp(node->children[2]))->expression->field;
            if (!e->type->equals(type))
                semantic_error(ErrorType::SemanticType5, node->lineno, "");
        }
    }
};