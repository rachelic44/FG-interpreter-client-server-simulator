//
// Created by user on 17/12/18.
//

#ifndef PROJECT_SHUNTINGYARD_H
#define PROJECT_SHUNTINGYARD_H
#include <iostream>
#include "Expression.h"
#include "BinaryExpression.h"
#include "UnaryExpression.h"
#include "Plus.h"
#include "Minus.h"
#include "Divide.h"
#include "Multiply.h"
#include "Number.h"
#include "LexerParser.h"
#include <stack>
#include <queue>
#include <deque>
#include <map>
using namespace std;

class ShuntingYard : public Expression {

private:
    map<string,double>* valMap;
    vector<string>::iterator* it;
    string tokens;
    void addAnArithmetic(stack<char>* operatorStack, stack<string>* finalStack, char act);
    void refeal(stack<char>* operatorStack, stack<string>* finalStack);
    Expression* calculate(stack<string>* finalStack);
    int precedence(char op);

public:
    string evaluateTokens(vector<string>::iterator* it);
    ShuntingYard(map<string, double>* map1, vector<string>::iterator* it);
    double evaluate();
    virtual void setValues(Expression* exp1,Expression* exp2){

    }



};


#endif //PROJECT_SHUNTINGYARD_H
