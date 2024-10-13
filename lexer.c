#include "lexer.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Token token;

const char* tokenType[] = {
    "LSQUIRLY", "RSQUIRLY", "LPAREN", "RPAREN", "SEMICOLON", "COMMA", "PLUS",
    "MINUS", "MULTIPLY", "DIVIDE", "ASSIGN", "GREATER", "LESS", "NOT",
    "NUMBER", "CHAR", "UNKNOWN", "IDENTIFIER", "KEYWORD"
};

const char* keywords[] = {
    "if", "else", "while", "for", "int", "char", "float", "double", "void",
    "return", "break", "continue", "switch", "case", "default", "struct",
    "enum", "typedef", "sizeof", "auto", "register", "static", "extern",
    "const", "volatile", "signed", "unsigned", "short", "long", "union",
    "do", "goto", "asm", "inline", "restrict", "bool", "true", "false", "NULL",
    NULL
};

bool isKeyword(const char *s) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(s, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

void lex(char *source) {
    char temp_token[100];
    int j = 0;

    for (int i = 0; source[i] != '\0'; i++) {
        char t = source[i];

        if (t == ' ' || t == '\n') {
            continue;
        }

        memset(temp_token, 0, sizeof(temp_token));
        j = 0;

        switch (t) {
            case '{': token.type = LSQUIRLY; token.value = '{'; break;
            case '}': token.type = RSQUIRLY; token.value = '}'; break;
            case '(': token.type = LPAREN; token.value = '('; break;
            case ')': token.type = RPAREN; token.value = ')'; break;
            case ';': token.type = SEMICOLON; token.value = ';'; break;
            case ',': token.type = COMMA; token.value = ','; break;
            case '+': token.type = PLUS; token.value = '+'; break;
            case '-': token.type = MINUS; token.value = '-'; break;
            case '*': token.type = MULTIPLY; token.value = '*'; break;
            case '/': token.type = DIVIDE; token.value = '/'; break;
            case '=': token.type = ASSIGN; token.value = '='; break;
            case '>': token.type = GREATER; token.value = '>'; break;
            case '<': token.type = LESS; token.value = '<'; break;
            case '!': token.type = NOT; token.value = '!'; break;
            case '0' ... '9': token.type = NUMBER; token.value = t; break;

            case 'a' ... 'z':
            case 'A' ... 'Z': {
                while ((isalnum(source[i]) || source[i] == '_') && source[i] != '\0' && j < sizeof(temp_token) - 1) {
                    temp_token[j++] = source[i++];
                }
                temp_token[j] = '\0';
                i--;

                if (isKeyword(temp_token)) {
                    token.type = KEYWORD;
                    strcpy(token.keyword, temp_token);
                } else {
                    token.type = IDENTIFIER;
                    strcpy(token.keyword, temp_token);
                }

                break;
            }

            default: {
                token.type = UNKNOWN;
                token.value = t;
                token.keyword[0] = '\0';
                break;
            }
        }

        if (token.type == IDENTIFIER || token.type == KEYWORD) {
            printf("Token: %s Type: %s \n", token.keyword, tokenType[token.type]);
        } else {
            printf("Token: %c Type: %s \n", token.value, tokenType[token.type]);
        }
    }
}

