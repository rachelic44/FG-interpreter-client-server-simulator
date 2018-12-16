//
// Created by user on 16/12/18.
//

#ifndef PROJECT_Minus_H
#define PROJECT_Minus_H


#include "BinaryExpression.h"

class Minus : public BinaryExpression {

public:
    Minus();
    Minus(Expression* exp1, Expression* expression2);
    double evaluate();

};


#endif //PROJECT_Minus_H
