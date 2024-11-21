#include <stdio.h>
#include "lexer.h"
 
int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    initializeLexer(argv[1]);
    processFile();

    return 0;
}

