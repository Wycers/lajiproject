//
// Created by Wycer on 2020/12/8.
//

#include <symbol_table.hpp>
#include <symbol_table_entry.h>
#include "def_list.h"

DefList::DefList(Node *node, bool insert_now) {
#ifdef debug
    printf("def_list\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
    fields = std::vector<Field *>();
    if (node && node->type == NodeType::DefList) {
        def = new Def(node->children[0]);
        fields = def->fields;
        if (insert_now) {
            for (int i = 0; i < fields.size(); i++) {
                SYMBOL_TABLE.insert(new SymbolTableEntry(fields[i], fields[i]->lineno));
            }
        }
        nextDefList = new DefList(node->children[1], insert_now);
        auto nextFields = nextDefList->fields;
        fields.insert(fields.end(), nextFields.begin(), nextFields.end());
    }
#ifdef debug
    printf("end\n");
#endif
}
