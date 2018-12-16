//
// Created by user on 16/12/18.
//

#ifndef PROJECT_PLUS_H
#define PROJECT_PLUS_H


#include "BinaryExpression.h"

class Plus : public BinaryExpression {

public:
    Plus();
    Plus(Expression* exp1, Expression* expression2);
    double evaluate();

};


#endif //PROJECT_PLUS_H
