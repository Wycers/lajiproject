//
// Created by Wycer on 2020/12/8.
//
#pragma once

#include "struct_specifier.hpp"

struct Specifier {
    Type *type = nullptr;
    StructSpecifier *structSpecifier = nullptr;

    Specifier(Node *node);
};