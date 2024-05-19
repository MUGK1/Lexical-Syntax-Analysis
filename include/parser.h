#ifndef PARSER_H
#define PARSER_H

void parseStatement();
void parseExpression();
void parseTerm();
void parseFactor();
void error(const char* message);
void parse();

#endif
