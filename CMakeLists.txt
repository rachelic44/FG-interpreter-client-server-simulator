cmake_minimum_required(VERSION 3.12)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project main.cpp UnaryExpression.h Expression.h BinaryExpression.h Plus.cpp Plus.h Number.cpp Number.h Minus.cpp Minus.h Divide.cpp Divide.h Multiply.cpp Multiply.h LexerParser.cpp LexerParser.h)