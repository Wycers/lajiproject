//
// Created by Wycer on 2020/12/8.
//

#include "def_list.h"
#include "stmt_list.hpp"

struct CompSt {

    DefList *defList;
    StmtList *stmtList;

    CompSt(Node *node, Type *ret_type) {
        new(this) CompSt(node, ret_type, std::vector<Field *>());
    }


    CompSt(Node *node, Type *ret_type, std::vector<Field *> params) {
#ifdef debug
        printf("comp_st\n");
#endif
        SYMBOL_TABLE.scope_push(ret_type);
        for (auto param : params)
            SYMBOL_TABLE.insert(new SymbolTableEntry(param, node->lineno));
        defList = new DefList(node->children[1], true);
        stmtList = new StmtList(node->children[2], ret_type);

        // SYMBOL_TABLE.print();

        SYMBOL_TABLE.scope_pop();
    }
};