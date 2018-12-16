//
// Created by user on 16/12/18.
//

#include "Plus.h"

Plus::Plus() : BinaryExpression() {

}

Plus::Plus(Expression *exp1, Expression *exp2) : BinaryExpression(exp1,exp2){

}

double Plus::evaluate() {
    return this->leftExpression->evaluate()+this->rightExpression->evaluate();
}