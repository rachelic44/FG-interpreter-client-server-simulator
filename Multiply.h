//
// Created by user on 16/12/18.
//

#ifndef PROJECT_Multiply_H
#define PROJECT_Multiply_H


#include "BinaryExpression.h"

class Multiply : public BinaryExpression {

public:
    Multiply();
    Multiply(Expression* exp1, Expression* expression2);
    double evaluate();

};


#endif //PROJECT_Multiply_H
