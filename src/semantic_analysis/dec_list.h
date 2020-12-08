//
// Created by Wycer on 2020/12/8.
//


#pragma once

#include "dec.hpp"

struct DecList {
    Dec *dec;
    DecList *nextDecList;
    std::vector<Field *> fields;

    DecList(Node *node, Type *type);
};