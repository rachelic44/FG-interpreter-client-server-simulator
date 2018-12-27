/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */
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
