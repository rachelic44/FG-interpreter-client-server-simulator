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
#include <map>

using namespace std;

void addAnArithmetic(stack<char>* operatorStack, queue<string>* queue1, char act);
void refeal(stack<char>* operatorStack, queue<string>* queue1);

/**
 * This function is to decide which precedence is higher
 * @param op op
 * @return 0 for wrong input
 */
int precedence(char op) {

    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

/**
 * This function gets a string of tokens and put it into a queue and a stack accordong to "Shating "Yard Algorithm"
 * @param tokens string
 * @return the value
 */
int evaluate(string tokens) {
    stack<char> operatorStack;
    queue<string> queue1;
    int i = 0;
    //go over the string
    while (i < tokens.length()) {
        //if it is (+ - / * ), then push it to the stack according to the arithmetic order
        if (tokens[i] == '+' || tokens[i] == '-' || tokens[i] == '/' || tokens[i] == '*') {
            addAnArithmetic(&operatorStack, &queue1, tokens[i]);
            i++;
            //if it is a digit, read all of the digits that comes after, then push the number to the stack
        } else if (isdigit(tokens[i])) {
            int val = 0;
            // There may be more than one digits in number.
            while (i < tokens.length() &&
                   isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            queue1.push(to_string(val));
            //if it's a left brace, push it to the operator stack
        } else if (tokens[i] == '(') {
            operatorStack.push(tokens[i]);
            i++;
            //if it is a right brace, push out all the items untill raching "("
        } else if (tokens[i] == ')') {
            i++;
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                refeal(&operatorStack,&queue1);
            }
        }
    }
    //push out all the items that are left.
    while (!operatorStack.empty()) {
        refeal(&operatorStack,&queue1);
    }


}

//take a char out of the stack of the operators and put it into the queue
void refeal(stack<char>* operatorStack, queue<string>* queue1) {
    char op = operatorStack->top();
    operatorStack->pop();
    string opStr;
    opStr.push_back(op);
    queue1->push(opStr);
}

//push a (+ - * / ) to the stack, if on the top there is another operator that has to come first, take
//it out and push it to the queue
void addAnArithmetic(stack<char>* operatorStack, queue<string>* queue1, char act) {

    if (!operatorStack->empty()) {
        char last = (operatorStack->top());
        if (precedence(last) > precedence(act)) {
            string opStr;
            opStr.push_back(last);
            queue1->push(opStr);
            operatorStack->pop();
        }
    }
    operatorStack->push(act);

}

double calculate(queue<string>* queue1) {
    map<char,Expression*> arithmeticMap={{'+',new Plus()},{'-',new Minus()},{'/',new Divide},{'*',new Multiply}};
    string current=queue1->front();
}


int main() {
/*
    LexerParser lexerParser;
    std::string s = "scott=tiger===mushroom";
    char delimiter = '=';
    vector<string> ss;
    ss = lexerParser.splitter(s, delimiter);
    for (int i = 0; i < ss.size(); i++)
        cout << ss[i] << '\n';*/

string p="5+60/3";
evaluate(p);
cout<<"G";


    return 0;
}
