/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#include "ExpressionCommand.h"

ExpressionCommand::ExpressionCommand(Command* c) {
    this->command=c;
}


double ExpressionCommand::evaluate() {
    return this->command->excecute();
}

void ExpressionCommand::setValues(Expression *exp1, Expression *exp2) {

}