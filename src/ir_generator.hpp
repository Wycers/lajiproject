#pragma once

#include "../syntax.tab.h"
#include "../type.hpp"
#include "error.h"
#include "node.h"

#include <symbol_table.hpp>
#include <vector>
#include <unordered_set>

class Program {


}

void program(Node *node)
{
    ext_def_list(node->children[0]);
}

void ir_generate(Node *root)
{
    program(root);
}