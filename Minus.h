/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */
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
