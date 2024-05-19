#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../include/lexer.h"

char input[1000];
int pos = 0;

void readInput() {
    printf("Enter The Code (end with 'END' on a new line):\n");
    int len = 0;
    char line[1000];

    while (1) {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }
        if (strncmp(line, "END", 3) == 0) {
            break;
        }
        int line_len = strlen(line);
        if (len + line_len < sizeof(input)) {
            strcpy(&input[len], line);
            len += line_len;
        } else {
            printf("Input too long, truncated.\n");
            break;
        }
    }
    pos = 0;
}

Token getNextToken() {
    Token token;
    token.lexeme[0] = '\0';

    while (input[pos] != '\0') {
        char currentChar = input[pos];
        if (isspace(currentChar)) {
            pos++;
            continue;
        }

        if (currentChar == '=') {
            token.type = TOKEN_ASSIGN;
            token.lexeme[0] = currentChar;
            token.lexeme[1] = '\0';
            pos++;
            return token;
        }

        if (currentChar == '+') {
            token.type = TOKEN_PLUS;
            token.lexeme[0] = currentChar;
            token.lexeme[1] = '\0';
            pos++;
            return token;
        }

        if (currentChar == '-') {
            token.type = TOKEN_MINUS;
            token.lexeme[0] = currentChar;
            token.lexeme[1] = '\0';
            pos++;
            return token;
        }

        if (currentChar == '*') {
            token.type = TOKEN_MULTIPLY;
            token.lexeme[0] = currentChar;
            token.lexeme[1] = '\0';
            pos++;
            return token;
        }

        if (currentChar == '/') {
            token.type = TOKEN_DIVIDE;
            token.lexeme[0] = currentChar;
            token.lexeme[1] = '\0';
            pos++;
            return token;
        }

        if (currentChar == '>') {
            token.type = TOKEN_GREATER;
            token.lexeme[0] = currentChar;
            token.lexeme[1] = '\0';
            pos++;
            return token;
        }

        if (currentChar == '(') {
            token.type = TOKEN_LEFT_PAREN;
            token.lexeme[0] = currentChar;
            token.lexeme[1] = '\0';
            pos++;
            return token;
        }

        if (currentChar == ')') {
            token.type = TOKEN_RIGHT_PAREN;
            token.lexeme[0] = currentChar;
            token.lexeme[1] = '\0';
            pos++;
            return token;
        }

        if (isalpha(currentChar)) {
            int start = pos;
            while (isalnum(input[pos])) pos++;
            strncpy(token.lexeme, &input[start], pos - start);
            token.lexeme[pos - start] = '\0';

            if (isdigit(token.lexeme[0])) {
                token.type = TOKEN_ERROR;
                return token;
            }

            if (strcmp(token.lexeme, "if") == 0) token.type = TOKEN_IF;
            else if (strcmp(token.lexeme, "then") == 0) token.type = TOKEN_THEN;
            else if (strcmp(token.lexeme, "else") == 0) token.type = TOKEN_ELSE;
            else token.type = TOKEN_IDENTIFIER;

            return token;
        }

        if (isdigit(currentChar)) {
            int start = pos;
            while (isdigit(input[pos])) pos++;
            if (isalpha(input[pos])) {
                while (isalnum(input[pos])) pos++;
                strncpy(token.lexeme, &input[start], pos - start);
                token.lexeme[pos - start] = '\0';
                token.type = TOKEN_ERROR;
                return token;
            } else {
                strncpy(token.lexeme, &input[start], pos - start);
                token.lexeme[pos - start] = '\0';
                token.type = TOKEN_NUMBER;
                return token;
            }
        }

        token.type = TOKEN_ERROR;
        token.lexeme[0] = currentChar;
        token.lexeme[1] = '\0';
        pos++;
        return token;
    }

    token.type = TOKEN_END;
    return token;
}

void printToken(Token token) {
    switch (token.type) {
        case TOKEN_IDENTIFIER: printf("Token(Identifier, %s)\n", token.lexeme); break;
        case TOKEN_NUMBER: printf("Token(Number, %s)\n", token.lexeme); break;
        case TOKEN_ASSIGN: printf("Token(Assignment Operator, %s)\n", token.lexeme); break;
        case TOKEN_IF: printf("Token(Keyword, if)\n"); break;
        case TOKEN_THEN: printf("Token(Keyword, then)\n"); break;
        case TOKEN_ELSE: printf("Token(Keyword, else)\n"); break;
        case TOKEN_PLUS: printf("Token(Plus, %s)\n", token.lexeme); break;
        case TOKEN_MINUS: printf("Token(Minus, %s)\n", token.lexeme); break;
        case TOKEN_MULTIPLY: printf("Token(Multiply, %s)\n", token.lexeme); break;
        case TOKEN_DIVIDE: printf("Token(Divide, %s)\n", token.lexeme); break;
        case TOKEN_GREATER: printf("Token(Greater, %s)\n", token.lexeme); break;
        case TOKEN_LEFT_PAREN: printf("Token(Left Parenthesis, %s)\n", token.lexeme); break;
        case TOKEN_RIGHT_PAREN: printf("Token(Right Parenthesis, %s)\n", token.lexeme); break;
        case TOKEN_ERROR: printf("Token(Error, %s)\n", token.lexeme); break;
        case TOKEN_END: printf("Token(End of Input)\n"); break;
        default: printf("Token(Unknown)\n"); break;
    }
}







