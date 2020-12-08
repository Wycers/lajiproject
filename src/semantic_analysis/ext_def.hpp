//
// Created by Wycer on 2020/12/8.
//


#pragma once

#include <src/node/node.h>
#include <symbol_table.hpp>
#include <type.hpp>
#include "comp_st.h"
#include "specifier.h"
#include "fun_dec.hpp"
#include "ext_dec_list.hpp"

#include "base.hpp"

struct ExtDef {

    CompSt *compSt;
    Specifier *specifier;
    ExtDecList *extDecList;
    FunDec *funDec;

    ExtDef(Node *node) {
#ifdef debug
        printf("ext_def\n");
    printf("%d\n", (int)node->type);
#endif
        specifier = new Specifier(node->children[0]);
        Type *type = specifier->type;
        if (node->type == NodeType::Declare) {
            _type_exist(type, node->lineno);
            extDecList = new ExtDecList(node->children[1], type);
            auto fields = extDecList->fields;
            for (auto field : fields)
                SYMBOL_TABLE.insert(new SymbolTableEntry(field, field->lineno));
        } else if (node->type == NodeType::StructDef) {
            if (type->category == Category::STRUCT) {
                SYMBOL_TABLE.insert(new SymbolTableEntry(type, node->lineno));
            }
        } else if (node->type == NodeType::FuncDef) {
            _type_exist(type, node->lineno);
            funDec = new FunDec(node->children[1], type);
            Func *func = funDec->func;
            SYMBOL_TABLE.insert(new SymbolTableEntry(func, node->lineno));
            compSt = new CompSt(node->children[2], type, func->params);
        }
    }
};
