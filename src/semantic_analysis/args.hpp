//
// Created by Wycer on 2020/12/8.
//

#pragma once

#include "exp.h"

struct Args {

    std::vector<Field *> fields;

    Args *nextArgs = nullptr;

    Args(Node *node) {
        Field *e = (new Exp(node->children[0]))->expression->field;
        fields = std::vector<Field *>{e};
        if (node->type == NodeType::ArgsMultiple) {
            nextArgs = new Args(node->children[2]);
            auto tail = nextArgs->fields;
            fields.insert(fields.end(), tail.begin(), tail.end());
        }
    }
};