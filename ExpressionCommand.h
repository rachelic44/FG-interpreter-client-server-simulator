//
// Created by user on 18/12/18.
//

#ifndef PROJECT_EXPRESSIONCOMMAND_H
#define PROJECT_EXPRESSIONCOMMAND_H

#include "Expression.h"
#include "Command.h"

class ExpressionCommand : public Expression {
private:
    Command* command;
public:
    ExpressionCommand(Command* c);
    virtual double evaluate();
    virtual void setValues(Expression* exp1,Expression* exp2);
};


#endif //PROJECT_EXPRESSIONCOMMAND_H
