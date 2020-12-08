//
// Created by Wycer on 2020/12/8.
//

#include "type.hpp"
#include "symbol_table.hpp"
#include "symbol_table_entry.h"

char *id(Node *node) {
    return node->text;
}

Type *_type_exist(Type *type, int lineno) {
    if (type->category != Category::STRUCT)
        return nullptr;
    auto entry = SYMBOL_TABLE.find(type->structure->name, EntryType::TYPE);
    if (entry == nullptr)
        return nullptr;
    Type *t = entry->type;
    if (t == nullptr)
        semantic_error(lineno, "Type not exist"); //, type->structure->name.c_str());
    return t;
}


