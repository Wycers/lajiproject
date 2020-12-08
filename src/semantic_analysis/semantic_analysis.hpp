#pragma once

#include "../syntax.tab.h"
#include "../type.hpp"
#include "error.h"
#include "node.h"

#include <symbol_table.hpp>
#include <vector>
#include <unordered_set>

#include "program.hpp"

Type *type(Node *node) {
#ifdef debug
    printf("node_token: %d\n", node->_token);
#endif
    if (node->_token == TYPE) {
        if (strcmp(node->text, "int") == 0)
            return new Type(Primitive::INT);
        else if (strcmp(node->text, "float") == 0)
            return new Type(Primitive::FLOAT);
        else if (strcmp(node->text, "char") == 0)
            return new Type(Primitive::CHAR);
    }
    return new Type((Primitive) node->type);
}

Program *semantic_analysis(Node *root) {
    return new Program(root);
}
