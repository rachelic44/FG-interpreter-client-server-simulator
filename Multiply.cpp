/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#include "Multiply.h"

Multiply::Multiply() : BinaryExpression() {

}

Multiply::Multiply(Expression *exp1, Expression *exp2) : BinaryExpression(exp1,exp2){

}

double Multiply::evaluate() {
    return this->leftExpression->evaluate()*this->rightExpression->evaluate();
}