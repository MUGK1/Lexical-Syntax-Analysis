# Lexical and Syntax Analyzer

This project implements a lexical and syntax analyzer in C, based on the assignment requirements. The lexical analyzer is responsible for tokenizing input code, identifying tokens such as identifiers, numbers, operators, and keywords. The syntax analyzer uses a recursive-descent parsing algorithm to validate the syntactic structure of the tokenized input.

## Features

1. **Lexical Analysis**:
    - Identifies and tokenizes keywords (`if`, `then`, `else`), identifiers, numbers, and operators.
    - Reports errors in illegal identifiers (e.g., `2sum`) and illegal integer literals (e.g., `23b2`).
    - Handles assignment operators and specific keywords.

2. **Syntax Analysis**:
    - Implements a recursive-descent parser for validating expressions based on EBNF.
    - Handles assignment statements and arithmetic expressions.
    - Includes error handling to report unexpected tokens and mismatched parentheses.

## Files

- `src/lexer.c`: Implementation of the lexical analyzer.
- `include/lexer.h`: Header file for the lexical analyzer.
- `src/parser.c`: Implementation of the syntax analyzer.
- `include/parser.h`: Header file for the syntax analyzer.
- `src/main.c`: Main program to read input, perform lexical analysis, and then syntax analysis.
- `CMakeLists.txt`: CMake configuration file for building the project.

## How to Build

1. **Prerequisites**:
    - CMake
    - A C compiler (e.g., gcc or clang)

2. **Steps**:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
    ```


## Build Happily by

- Khaled Almansour 