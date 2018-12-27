cmake_minimum_required(VERSION 3.12)
project(project14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

include_directories(.)

add_executable(project14
    cmake-build-debug/CMakeCache.txt
    BinaryExpression.h
    BindCommand.cpp
    BindCommand.h
    BoolSingelton.h
    BoundMap.h
    CMakeLists.txt
    Command.h
    CommandAssign.cpp
    CommandAssign.h
        CommandVar.cpp
    CommandVar.h
    ConditionParser.cpp
    ConditionParser.h
    ConnectCommand.cpp
    ConnectCommand.h
        DictionaryPath.h
    Divide.cpp
    Divide.h
        Expression.h
    ExpressionCommand.cpp
    ExpressionCommand.h
    ExpressionFactory.cpp
    ExpressionFactory.h
    IfCommand.cpp
    IfCommand.h
    LexerParser.cpp
    LexerParser.h
    main.cpp
    Minus.cpp
    Minus.h
    Multiply.cpp
    Multiply.h
    Number.cpp
    Number.h
    OpenDataServerCommand.cpp
    OpenDataServerCommand.h
        Plus.cpp
    Plus.h
        PrintCommand.cpp
    PrintCommand.h
    ShuntingYard.cpp
    ShuntingYard.h
    SleepCommand.cpp
    SleepCommand.h
    SymbolTableMap.h
        WhileCommand.cpp
    WhileCommand.h)
