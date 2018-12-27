/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#include "Number.h"

double Number::evaluate() {
    return stod(this->value);
}

string Number::getValue() {
    return this->value;
}

void Number::setValues(Expression *exp1, Expression *exp2) {

}