//
// Created by user on 18/12/18.
//

#include "ExpressionCommand.h"

ExpressionCommand::ExpressionCommand(Command* c) {
    this->command=c;
}


double ExpressionCommand::evaluate() {
    return this->command->excecute();
}

void ExpressionCommand::setValues(Expression *exp1, Expression *exp2) {

}