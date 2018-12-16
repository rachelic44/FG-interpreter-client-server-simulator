//
// Created by user on 16/12/18.
//

#include "Divide.h"

Divide::Divide() : BinaryExpression() {

}

Divide::Divide(Expression *exp1, Expression *exp2) : BinaryExpression(exp1,exp2){

}

double Divide::evaluate() {
    return this->leftExpression->evaluate()/this->rightExpression->evaluate();
}