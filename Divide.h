//
// Created by user on 16/12/18.
//

#ifndef PROJECT_Divide_H
#define PROJECT_Divide_H


#include "BinaryExpression.h"

class Divide : public BinaryExpression {

public:
    Divide();
    Divide(Expression* exp1, Expression* expression2);
    double evaluate();

};


#endif //PROJECT_Divide_H
