//
// Created by user on 16/12/18.
//

#ifndef PROJECT_EXPRESSION_H
#define PROJECT_EXPRESSION_H

/**
 * Interface Expression. represents an expression with the abilities of calculating the expression's value,
 * simplifying, differentiating an centre.
 *
 * @author Racheli copperman. User: copperr. ID: 315597575
 */
class Expression {

public:
    /**
     * Evaluate function. A convenience method. evaluates the value of a given expression, by
     * creating an empty map and calls with it to the regular evaluate function.
     *
     * @return the double value of the expression
     * @throws Exception in case the expression is illegal and can not be evaluated, like 5/0.
     */
     virtual double evaluate()=0;

     virtual void setValues(Expression* exp1,Expression* exp2)=0;


};

#endif //PROJECT_EXPRESSION_H
