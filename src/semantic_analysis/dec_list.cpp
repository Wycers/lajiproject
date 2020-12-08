//
// Created by Wycer on 2020/12/8.
//

#include "dec_list.h"

DecList::DecList(Node *node, Type *type) {
#ifdef debug
    printf("dec_list\n");
    if (node)
        printf("lineno: %d\n", node->lineno);
#endif
    dec = new Dec(node->children[0], type);
    Field *field = dec->field;
    fields = std::vector<Field *>{field};
    if (node->type == NodeType::VarDecListMultiple) {
        nextDecList = new DecList(node->children[2], type);
        auto nextFields = nextDecList->fields;
        fields.insert(fields.end(), nextFields.begin(), nextFields.end());
    }
}
