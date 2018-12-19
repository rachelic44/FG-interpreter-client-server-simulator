cmake_minimum_required(VERSION 3.12)
project(project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
add_executable(project main.cpp UnaryExpression.h Expression.h BinaryExpression.h Plus.cpp Plus.h Number.cpp Number.h Minus.cpp Minus.h Divide.cpp Divide.h Multiply.cpp Multiply.h LexerParser.cpp LexerParser.h Command.h CommandAssign.cpp CommandAssign.h CommandVar.cpp CommandVar.h ShuntingYard.cpp ShuntingYard.h ExpressionCommand.cpp ExpressionCommand.h ExpressionFactory.cpp ExpressionFactory.h ConditionParser.cpp ConditionParser.h IfCommand.cpp IfCommand.h WhileCommand.cpp WhileCommand.h OpenServerCommand.cpp OpenServerCommand.h)