#include "lexer.h"
#include <stdio.h>

int main() {
    FILE *file = fopen("source.txt", "r");
    char source_code[100];

    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }

    while (fgets(source_code, 100, file) != NULL) {}

    fclose(file);

    lex(source_code);

    return 0;
}
