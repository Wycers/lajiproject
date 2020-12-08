//
// Created by Wycer on 2020/12/8.
//

#pragma once

#include <src/node/node.h>

#include "ext_def.hpp"

struct ExtDefList {
    ExtDef *extDef;
    ExtDefList *extDefList;

    ExtDefList(Node *node) {
#ifdef debug
        printf("ext_def_list\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
        if (node && node->type == NodeType::ExtDefList) {
            extDef = new ExtDef(node->children[0]);
            extDefList = new ExtDefList(node->children[1]);
        }
    }
};
