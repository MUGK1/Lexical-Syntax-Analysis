#ifndef LEXER_H
#define LEXER_H

// Types of tokens
typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_ASSIGN,
    TOKEN_IF,
    TOKEN_THEN,
    TOKEN_ELSE,
    TOKEN_ERROR,
    TOKEN_END,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_GREATER,
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
} TokenType;

// Structure of the token
typedef struct {
    TokenType type;
    char lexeme[100];
} Token;

// Variables
extern char input[1000];
extern int pos;

// Functions
void readInput();
Token getNextToken();
void printToken(Token token);

#endif
