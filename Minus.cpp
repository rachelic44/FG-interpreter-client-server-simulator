/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#include "Minus.h"

Minus::Minus() : BinaryExpression() {

}

Minus::Minus(Expression *exp1, Expression *exp2) : BinaryExpression(exp1,exp2){

}

double Minus::evaluate() {
    return this->leftExpression->evaluate()-this->rightExpression->evaluate();
}