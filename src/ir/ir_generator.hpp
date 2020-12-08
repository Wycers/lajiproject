

#include "semantic_analysis.hpp"

IRList &operator+=(IRList &a, const IRList b) {
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

IRList Program::generate() {
    SYMBOL_TABLE.clear();

    auto irs = IRList();
    if (extDefList != nullptr) {
        irs += extDefList->generate();
    }
    return irs;
}

IRList ExtDefList::generate() {
    auto irs = IRList();
    if (extDef != nullptr) {
        irs += extDef->generate();
    }
    if (extDefList != nullptr) {
        irs += extDefList->generate();
    }
    return irs;
}

IRList ExtDef::generate() {
    auto irs = IRList();
//    Type *type = specifier->type;
//    if (node->type == NodeType::Declare) {
//        extDecList = new ExtDecList(node->children[1], type);
//        auto fields = extDecList->fields;
//        for (auto field : fields)
//            SYMBOL_TABLE.insert(new SymbolTableEntry(field, field->lineno));
//    }
//    if (node->type == NodeType::StructDef) {
//        if (type->category == Category::STRUCT) {
//            SYMBOL_TABLE.insert(new SymbolTableEntry(type, node->lineno));
//        }
//    }
    if (this->node->type == NodeType::FuncDef) {
        Func *func = funDec->func;
        SYMBOL_TABLE.insert(new SymbolTableEntry(func, node->lineno));
        irs += funDec->generate();
        irs += compSt->generate();
    }
    return irs;
}

IRList FunDec::generate() {
    auto irs = IRList();
    irs.push_back(new FUNCTION_IR({name}));
    return irs;
}

IRList CompSt::generate() {
    auto irs = IRList();
    SYMBOL_TABLE.scope_push(ret_type);

    for (auto param : params) {
        auto entry = new SymbolTableEntry(param, node->lineno);
        irs.push_back(new PARAM_IR({entry->name()}));
        SYMBOL_TABLE.insert(entry);
    }
    irs += defList->generate();
    irs += stmtList->generate();

    SYMBOL_TABLE.scope_pop();
    return irs;
}


IRList DefList::generate() {
    auto irs = IRList();

    return irs;
}

IRList StmtList::generate() {
    auto irs = IRList();

    if (stmt != nullptr) {
        irs += stmt->generate();
    }
    if (nextStmtList != nullptr) {
        irs += nextStmtList->generate();
    }

    return irs;
}

IRList Stmt::generate() {
    auto irs = IRList();

    return irs;
}