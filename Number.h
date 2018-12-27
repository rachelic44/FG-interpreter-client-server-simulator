/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#ifndef PROJECT_NUMBER_H
#define PROJECT_NUMBER_H


#include "Expression.h"
#include <iostream>
using namespace std;

class Number: public Expression {




private: string value;

/**
* constructor.
*
* @param number is the number.
 */
public:

    Number(string number) {
            this->value = number;
        }


        /**
         * Evaluate function. evaluates the value of a given expression.
         *
         * @return the double value of the expression
         * @throws Exception in no case. number always know to calculate it's value.
         */
        double evaluate();

        virtual void setValues(Expression* exp1,Expression* exp2);

        /**
         * getValue().
         *
         * @return the value of the number.
         */
        string getValue();

        ~Number() =default;


};


#endif //PROJECT_NUMBER_H
