//
// Created by user on 16/12/18.
//

#ifndef PROJECT_UNARYEXPRESSION_H
#define PROJECT_UNARYEXPRESSION_H

#include "Expression.h"

/**
 * UnaryExpression Class, Abstract class. The class measures an unary expression, that has one expression. for example-
 * cos(x), sin(x)..
 *
 * @author Racheli copperman. User: copperr. ID: 315597575
 */
class UnaryExpression : public Expression {
//member
protected:
    Expression* expression;

/**
 * constructor.
 *
 * @param expression is the expression of the unary expression.
 */
public:




    /**
 * getExpression.
 *
 * @return the expression of the unary expression.
 */
    virtual Expression* getExpression() {
        return this->expression;
    }

    /**
 * setExpression.
 *
 * @param expressionTo is the expression to exchange with.
 */
    virtual void setExpression(Expression* expressionTo) {
        this->expression = expressionTo;
    }



};
#endif //PROJECT_UNARYEXPRESSION_H
