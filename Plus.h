/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

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
