#ifndef LEXER_H
#define LEXER_H

#include <stdbool.h>

enum TokenType {
    LSQUIRLY, RSQUIRLY, LPAREN, RPAREN, SEMICOLON, COMMA, PLUS, MINUS,
    MULTIPLY, DIVIDE, ASSIGN, GREATER, LESS, NOT, NUMBER, CHAR, UNKNOWN,
    IDENTIFIER, KEYWORD
};

struct Token {
    enum TokenType type;
    char value;
    char keyword[100];
};

extern struct Token token;

extern const char* tokenType[];

bool isKeyword(const char *s);
void lex(char *source);

#endif
