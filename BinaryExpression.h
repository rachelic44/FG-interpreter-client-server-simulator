//
// Created by user on 16/12/18.
//

#ifndef PROJECT_BINARYEXPRESSION_H
#define PROJECT_BINARYEXPRESSION_H

#include "Expression.h"
/**
 * BinaryExpression Class, Abstract class. The class measures a binary expression, that has left expression and
 * right expression as members.
 *
 * @author Racheli copperman. User: copperr. ID: 315597575
 */
class BinaryExpression : public Expression {

protected:
    Expression* rightExpression;
    Expression* leftExpression;


/**
 * constructor.
 *
 * @param leftExpression  is the left expression.
 * @param rightExpression is the right expression.
 */
public:
    BinaryExpression() {
        this->rightExpression=nullptr;
        this->leftExpression= nullptr;
    }

    BinaryExpression(Expression* leftExpression, Expression* rightExpression) {
      this->leftExpression = leftExpression;
      this->rightExpression = rightExpression;
}


    virtual Expression* getLeftExpression() {
    return leftExpression;
}


    virtual Expression* getRightExpression() {
    return rightExpression;
}


virtual void setLeftExpression(Expression* leftExpressionGiven) {
      this->leftExpression = leftExpressionGiven;
}

/**
 * setRightExpression.
 *
 * @param rightExpressionnGiven is the new expression
 */
virtual void setRightExpression(Expression* rightExpressionnGiven) {
        this->rightExpression = rightExpression;

}

virtual void setValues(Expression* exp1,Expression* exp2) {
    this->leftExpression=exp1;
    this->rightExpression=exp2;
}

double evaluate() {
    
}

~BinaryExpression() {
    delete this->leftExpression;
    delete this->rightExpression;
}
};
#endif //PROJECT_BINARYEXPRESSION_H
