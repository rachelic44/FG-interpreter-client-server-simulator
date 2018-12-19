//
// Created by user on 16/12/18.
//

#include "Number.h"

double Number::evaluate() {
    return stoi(this->value);
}

string Number::getValue() {
    return this->value;
}

void Number::setValues(Expression *exp1, Expression *exp2) {

}