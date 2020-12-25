#include <iostream>


#include "src/semantic_analysis/semantic_analysis.hpp"
#include "src/ir/ir_generator.hpp"
#include "syntax.tab.c"
#include "optimizer.hpp"

int main(int argc, char **argv) {

    char *filename = argv[1];


    FILE *fin = NULL;
    extern FILE *yyin;
    fin = fopen(filename, "r");

    if (fin == NULL) {
        printf("cannot open reading file.\n");
        return -1;
    }
    yyin = fin;
    /* yydebug = 1; */
    yyparse();
    fclose(fin);

//    int len = strlen(filename);
//    filename[len - 3] = 'o';
//    filename[len - 2] = 'u';
//    filename[len - 1] = 't';
//
//    freopen(filename, "w", stdout);
    display(root_node, 0);

    auto program = semantic_analysis(root_node);

    if (has_error()) {
        print_errors();
        return -1;
    }

    auto irs = program->generate();
//    std::freopen("/home/wycer/test_env/ir", "w", stdout);
//    for (auto ir: irs) {
//        cout << ir->str() << endl;
//    }


    auto opt_irs = optimize(irs);
    std::freopen("/home/wycer/test_env/ir_opt", "w", stdout);
    for (auto ir: irs) {
        cout << ir->str() << endl;
    }
    fclose(stdout);

    /* SYMBOL_TABLE.print(); */

    return 0;

}

