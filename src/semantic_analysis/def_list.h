//
// Created by Wycer on 2020/12/8.
//

#pragma once

#include "def.hpp"

struct DefList {

    Def *def;
    DefList *nextDefList;

    std::vector<Field *> fields;

    DefList(Node *node, bool insert_now = false);
};
