#include <iostream>


#include "src/semantic_analysis/semantic_analysis.hpp"
#include "syntax.tab.c"

int main(int argc, char **argv){

    char *filename = argv[1];


    FILE* fin = NULL;
    extern FILE* yyin;
    fin = fopen(filename, "r");

    if(fin == NULL)
    {
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

    semantic_analysis(root_node);

    if (has_error()) {
        print_errors();
        return -1;
    }

    /* display(root_node, 0); */

    /* SYMBOL_TABLE.print(); */

    fclose(stdout);
    return 0;

}

