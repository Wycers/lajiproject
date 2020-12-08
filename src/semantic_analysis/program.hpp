//
// Created by Wycer on 2020/12/8.
//

#pragma once

#include <src/node/node.h>
#include "ext_def_list.hpp"

struct Program {
    ExtDefList *extDefList;

    Program(Node *node) {
#ifdef debug
        printf("program\n");
#endif
        extDefList = new ExtDefList(node->children[0]);
    }
};