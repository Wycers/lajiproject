//
// Created by Wycer on 2020/12/8.
//

#include <node.h>

struct Expression {
    struct Field *field;
    bool isLeftValue;
};

struct Exp {
    Expression *expression;
    Exp(Node *node);
};
