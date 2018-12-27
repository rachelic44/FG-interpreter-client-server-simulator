/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

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
