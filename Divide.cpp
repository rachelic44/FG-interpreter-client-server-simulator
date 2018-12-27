/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#include "Divide.h"

Divide::Divide() : BinaryExpression() {

}

Divide::Divide(Expression *exp1, Expression *exp2) : BinaryExpression(exp1,exp2){

}

double Divide::evaluate() {
    return this->leftExpression->evaluate()/this->rightExpression->evaluate();
}