#include <stdio.h>
#include <stdlib.h>
#include "../include/lexer.h"
#include "../include/parser.h"

Token currentToken;

const char* tokenTypeName(TokenType type) {
    switch (type) {
        case TOKEN_IDENTIFIER: return "Identifier";
        case TOKEN_NUMBER: return "Number";
        case TOKEN_ASSIGN: return "Assignment Operator";
        case TOKEN_IF: return "Keyword 'if'";
        case TOKEN_THEN: return "Keyword 'then'";
        case TOKEN_ELSE: return "Keyword 'else'";
        case TOKEN_ERROR: return "Error";
        case TOKEN_END: return "End of Input";
        case TOKEN_PLUS: return "Plus";
        case TOKEN_MINUS: return "Minus";
        case TOKEN_MULTIPLY: return "Multiply";
        case TOKEN_DIVIDE: return "Divide";
        case TOKEN_GREATER: return "Greater";
        case TOKEN_LEFT_PAREN: return "Left Parenthesis";
        case TOKEN_RIGHT_PAREN: return "Right Parenthesis";
        default: return "Unknown";
    }
}

void getNextTokenWrapper() {
    currentToken = getNextToken();
    printToken(currentToken);
}

void error(const char* message) {
    printf("Syntax Error: %s\n", message);
    printf("Error in: Token(%s, %s)\n", tokenTypeName(currentToken.type), currentToken.lexeme);
    exit(1);
}

void match(TokenType expectedType) {
    if (currentToken.type == expectedType) {
        getNextTokenWrapper();
    } else {
        char errorMessage[100];
        sprintf(errorMessage, "Expected token type %s but found %s", tokenTypeName(expectedType), tokenTypeName(currentToken.type));
        error(errorMessage);
    }
}

void parseExpression();

void parseFactor() {
    if (currentToken.type == TOKEN_IDENTIFIER || currentToken.type == TOKEN_NUMBER) {
        getNextTokenWrapper();
    } else if (currentToken.type == TOKEN_LEFT_PAREN) {
        getNextTokenWrapper();
        parseExpression();
        match(TOKEN_RIGHT_PAREN);
    } else {
        error("Unexpected token in factor");
    }
}

void parseTerm() {
    parseFactor();
    while (currentToken.type == TOKEN_MULTIPLY || currentToken.type == TOKEN_DIVIDE) {
        getNextTokenWrapper();
        parseFactor();
    }
}

void parseExpression() {
    parseTerm();
    while (currentToken.type == TOKEN_PLUS || currentToken.type == TOKEN_MINUS) {
        getNextTokenWrapper();
        parseTerm();
    }
}

void parseStatement() {
    if (currentToken.type == TOKEN_IDENTIFIER) {
        match(TOKEN_IDENTIFIER);
        match(TOKEN_ASSIGN);
        parseExpression();
    } else if (currentToken.type == TOKEN_NUMBER) {
        error("Invalid assignment: left-hand side must be an identifier");
    } else {
        parseExpression();
    }
}

void parse() {
    getNextTokenWrapper();
    while (currentToken.type != TOKEN_END) {
        parseStatement();
        if (currentToken.type == TOKEN_END) {
            break;
        }
    }
    if (currentToken.type == TOKEN_END) {
        printf("Code is correct\n");
    } else {
        error("Unexpected tokens at the end of expression");
    }
}


