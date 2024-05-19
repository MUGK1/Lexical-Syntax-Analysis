cmake_minimum_required(VERSION 3.15)
project(lexical_analyzer C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(lexical_analyzer src/main.c src/lexer.c
        src/parser.c)
