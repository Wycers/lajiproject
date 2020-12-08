//
// Created by Wycer on 2020/12/8.
//

#include "exp.h"

#include <type.hpp>
#include <error.h>
#include <symbol_table.hpp>
#include "args.hpp"


Exp::Exp(Node *node) {
#ifdef debug
    printf("exp\n");
if (node)
    printf("lineno: %d\n", node->lineno);
#endif
    auto c = node->children;
    auto error_expr = new Expression{
            new Field(new Type(Primitive::NotExpr), node->lineno),
            true};

    if (node->type == NodeType::ExpAssign) {
        auto exp1 = (new Exp(c[0]))->expression, exp2 = (new Exp(c[2]))->expression;
        if (!exp1->isLeftValue)
            semantic_error(ErrorType::SemanticType6, node->lineno, "");

        auto oprand1 = exp1->field, oprand2 = exp2->field;

        if (!oprand1->type->equals(oprand2->type)) {
            std::string msg =
                    to_str(oprand1->type) + "!=" + to_str(oprand2->type);
            semantic_error(ErrorType::SemanticType5, node->lineno, msg.c_str());
        }
        expression = new Expression{new Field{new Type(*oprand1->type), node->lineno}, false};
    }
    if (node->type == NodeType::ExpAnd || node->type == NodeType::ExpOr) {
        auto exp1 = (new Exp(c[0]))->expression, exp2 = (new Exp(c[2]))->expression;
        auto oprand1 = exp1->field, oprand2 = exp2->field;
        auto category_1 = oprand1->type->category;
        auto category_2 = oprand2->type->category;
        if (category_1 != Category::PRIMITIVE ||
            category_2 != Category::PRIMITIVE) {
            semantic_error(node->lineno,
                           "Only INT type can not be used in boolean operator",
                           "");
            expression = error_expr;
        }
        auto primitive_1 = oprand1->type->primitive;
        auto primitive_2 = oprand2->type->primitive;
        if (primitive_1 != Primitive::INT ||
            primitive_2 != Primitive::INT) {
            semantic_error(node->lineno,
                           "Only INT type can not be used in boolean operator",
                           "");
            expression = error_expr;
        }
        expression = new Expression{
                new Field{new Type(*oprand1->type), node->lineno},
                false};
    }
    if (node->type == NodeType::ExpLT ||
        node->type == NodeType::ExpGT ||
        node->type == NodeType::ExpLE ||
        node->type == NodeType::ExpGE ||
        node->type == NodeType::ExpEQ ||
        node->type == NodeType::ExpNE) {
        auto exp1 = (new Exp(c[0]))->expression, exp2 = (new Exp(c[2]))->expression;
        auto oprand1 = exp1->field, oprand2 = exp2->field;
        auto category_1 = oprand1->type->category;
        auto category_2 = oprand2->type->category;
        if (category_1 != Category::PRIMITIVE ||
            category_2 != Category::PRIMITIVE) {
            semantic_error(ErrorType::SemanticType7, node->lineno, "");
            expression = error_expr;
        }
        auto primitive_1 = oprand1->type->primitive;
        auto primitive_2 = oprand2->type->primitive;

        if (primitive_1 == Primitive::CHAR ||
            primitive_2 == Primitive::CHAR) {

            if (
                    node->type != NodeType::ExpEQ &&
                    node->type != NodeType::ExpNE) {

                semantic_error(node->lineno,
                               "CHAR type can not be used in arithmetic operator",
                               "");
                expression = error_expr;
            }
        }
        expression = new Expression{
                new Field{new Type(*oprand1->type), node->lineno},
                false};
    }
    if (node->type == NodeType::ExpPlus ||
        node->type == NodeType::ExpMinus ||
        node->type == NodeType::ExpMul ||
        node->type == NodeType::ExpDiv) {
        auto exp1 = (new Exp(c[0]))->expression, exp2 = (new Exp(c[2]))->expression;
        auto oprand1 = exp1->field, oprand2 = exp2->field;
        auto category_1 = oprand1->type->category;
        auto category_2 = oprand2->type->category;
        if (category_1 != Category::PRIMITIVE ||
            category_2 != Category::PRIMITIVE) {
            semantic_error(ErrorType::SemanticType7, node->lineno, "");
            expression = error_expr;
        }
        auto primitive_1 = oprand1->type->primitive;
        auto primitive_2 = oprand2->type->primitive;

        if (primitive_1 == Primitive::CHAR ||
            primitive_2 == Primitive::CHAR) {
            semantic_error(node->lineno,
                           "CHAR type can not be used in arithmetic operator",
                           "");
            expression = error_expr;
        }
        expression = new Expression{
                new Field{new Type(*oprand1->type), node->lineno},
                false};
    }
    if (node->type == NodeType::ExpNegative || node->type == NodeType::ExpNot) {
        auto oprand = (new Exp(c[1]))->expression->field;
        if (oprand->type->category != Category::PRIMITIVE) {
            semantic_error(node->lineno,
                           "Derived type can not be used in negative operator",
                           "");
            expression = error_expr;
        }
        if (node->type == NodeType::ExpNegative &&
            oprand->type->primitive == Primitive::CHAR) {
            semantic_error(node->lineno,
                           "CHAR type can not be used in negative operator",
                           "");
            expression = error_expr;
        }
        if (node->type == NodeType::ExpNot &&
            oprand->type->primitive != Primitive::INT) {
            semantic_error(node->lineno,
                           "Only INT type can be used in not operator",
                           "");
            expression = error_expr;
        }
        expression = new Expression{
                new Field{new Type(*oprand->type), node->lineno},
                false};
    }
    if (node->type == NodeType::ExpBracketWrapped) {
        auto e = (new Exp(c[1]))->expression->field;
        expression = new Expression{
                new Field{e->name, new Type(*(e->type)), e->lineno},
                false};
    }
    if (node->type == NodeType::ExpArgsFuncCall ||
        node->type == NodeType::ExpFuncCall) {
        std::string func_name = id(c[0]);
        auto func_entry = SYMBOL_TABLE.find(func_name, EntryType::FUNC);
        if (func_entry == nullptr) {s
            if (SYMBOL_TABLE.find(func_name))
                semantic_error(ErrorType::SemanticType11, node->lineno, func_name.c_str());
            else
                semantic_error(ErrorType::SemanticType2, node->lineno, func_name.c_str());
            expression = error_expr;
        }
        Func *func = func_entry->func;
        std::vector<Field *> arguments{};
        if (node->type == NodeType::ExpArgsFuncCall) {
            auto args = new Args(c[2]);
            arguments = args->fields;
        }
        if (func->params.size() != arguments.size()) {

            semantic_error(ErrorType::SemanticType9, node->lineno, func_name.c_str());

            expression = new Expression{
                    new Field{"Exp", new Type(*func->ret), node->lineno},
                    false};
        }
        for (int i = 0; i < arguments.size(); i++) {
            if (func->params[i]->type->equals(arguments[i]->type))
                continue;
            semantic_error(node->lineno,
                           "Argument type does not match",
                           func_name.c_str());
            expression = new Expression{
                    new Field{"Exp", new Type(*func->ret), node->lineno},
                    false};
        }
        expression = new Expression{
                new Field{new Type(*func->ret), node->lineno},
                false};
    }
    if (node->type == NodeType::ExpArrayIndex) {
        Field *field = (new Exp(c[0]))->expression->field;
        if (field->type->category != Category::ARRAY) {
            semantic_error(ErrorType::SemanticType10, node->lineno, field->name.c_str());
            expression = error_expr;
        }
        Array *arr = field->type->array;

        Field *idx = (new Exp(c[2]))->expression->field;
        if (idx->type->category != Category::PRIMITIVE ||
            idx->type->primitive != Primitive::INT) {
            semantic_error(ErrorType::SemanticType12, node->lineno, field->name.c_str());
            expression = error_expr;
        }
        expression = new Expression{
                new Field{new Type(*arr->type), node->lineno},
                true};
    }
    if (node->type == NodeType::ExpFiledAccess) {
        Field *s = (new Exp(c[0]))->expression->field;
        std::string field_name = id(c[2]);
        if (s->type->category != Category::STRUCT) {
            semantic_error(ErrorType::SemanticType13, node->lineno, s->name.c_str());
            expression = error_expr;
        }
        auto fields = s->type->structure->fields;
        for (auto i : fields) {
            if (i->name != field_name)
                continue;
            expression = new Expression{
                    new Field{new Type(*(i->type)), i->lineno},
                    true};
        }
        semantic_error(ErrorType::SemanticType14, node->lineno, field_name.c_str());
        expression = error_expr;
    }
    if (node->type == NodeType::ExpId) {
        std::string var_name = id(c[0]);
        auto var_entry = SYMBOL_TABLE.find(var_name, EntryType::FIELD);
        if (var_entry == nullptr) {
            semantic_error(ErrorType::SemanticType1, node->lineno, var_name.c_str());
            expression = error_expr;
        }
        expression = new Expression{
                new Field{new Type(*var_entry->field->type), var_entry->field->lineno},
                true};
    }
    if (node->type == NodeType::ExpInt) {
        expression = new Expression{
                new Field{new Type(Primitive::INT),
                          node->lineno},
                false};
    }
    if (node->type == NodeType::ExpChar) {
        expression = new Expression{
                new Field{new Type(Primitive::CHAR),
                          node->lineno},
                false};
    }
    if (node->type == NodeType::ExpFloat) {
        expression = new Expression{
                new Field{new Type(Primitive::FLOAT),
                          node->lineno},
                false};
    }

    expression = error_expr;
}
