//
// Created by Wycer on 2020/12/8.
//


#pragma once

#include <node.h>
#include <type.hpp>
#include <unordered_set>
#include <error.h>


#include "def_list.h"

struct StructSpecifier {
    DefList *defList;
    Type *type;

    StructSpecifier(Node *node) {
        Struct *structure = new Struct;
        structure->name = id(node->children[1]);
        structure->fields = std::vector<Field *>();

        if (node->type == NodeType::StructSpecifierWithBody) {
            defList = new DefList(node->children[3]);
            structure->fields = defList->fields;

            std::unordered_set<std::string> s;
            std::vector<Field *> res{};
            for (auto f : structure->fields) {
                if (s.find(f->name) != s.end())
                    semantic_error(f->lineno,
                                   "Repeated field name inside structure",
                                   f->name.c_str());
                s.insert(f->name);
            }
        }
        type = new Type(structure);
    }
};