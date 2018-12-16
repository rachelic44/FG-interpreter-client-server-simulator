//
// Created by user on 16/12/18.
//

#include "Multiply.h"

Multiply::Multiply() : BinaryExpression() {

}

Multiply::Multiply(Expression *exp1, Expression *exp2) : BinaryExpression(exp1,exp2){

}

double Multiply::evaluate() {
    return this->leftExpression->evaluate()*this->rightExpression->evaluate();
}