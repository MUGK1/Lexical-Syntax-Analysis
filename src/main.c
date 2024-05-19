#include <stdio.h>
#include "../include/lexer.h"
#include "../include/parser.h"

void performLexicalAnalysis() {
    Token token;
    printf("Lexical Analysis:\n");
    do {
        token = getNextToken();
        printToken(token);
    } while (token.type != TOKEN_END);
}

void performSyntaxAnalysis() {
    printf("\nSyntax Analysis:\n");
    pos = 0;
    parse();
}

int main() {
    readInput();
    performLexicalAnalysis();
    performSyntaxAnalysis();
    return 0;
}
