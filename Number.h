//
// Created by user on 16/12/18.
//

#ifndef PROJECT_NUMBER_H
#define PROJECT_NUMBER_H


#include "UnaryExpression.h"


class Number: public Expression {




private: double value;

/**
* constructor.
*
* @param number is the number.
 */
public:

    Number(double number) {
            this->value = number;
        }


        /**
         * Evaluate function. evaluates the value of a given expression.
         *
         * @return the double value of the expression
         * @throws Exception in no case. number always know to calculate it's value.
         */
        double evaluate();

        /**
         * getValue().
         *
         * @return the value of the number.
         */
        double getValue();

};


#endif //PROJECT_NUMBER_H
