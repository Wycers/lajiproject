//
// Created by Wycer on 2020/12/8.
//

#include "specifier.h"

Type *typeOf(Node *node) {
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


struct Specifier {
    Specifier(Node *node) {
#ifdef debug
        printf("specifier\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
        if (node == nullptr)
            return;
        if (node->type == NodeType::Specifier) {
            type = typeOf(node->children[0]);
        } else if (node->type == NodeType::StructSpecifier) {
            structSpecifier = new StructSpecifier(node->children[0]);
            type = structSpecifier->type;
        }
    }
};
