//
// Created by user on 17/12/18.
//

#include "ShuntingYard.h"


ShuntingYard::ShuntingYard(map<string, double>* map1,string tokens) {
    this->tokens=tokens;
    this->valMap=map1;
}

/**
* This function is to decide which precedence is higher
* @param op op
* @return 0 for wrong input
*/
int ShuntingYard::precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}


/**
 * This function gets a string of tokens and put it into a stack and a stack accordong to "Shating "Yard Algorithm"
 * @param tokens string
 * @return the value
 */
double ShuntingYard::evaluate() {
    string tokens=this->tokens;
    stack<char> operatorStack;
    stack<string> finalStack;
    int i = 0;
    //go over the string
    while (i < tokens.length()) {
        //if it is (+ - / * ), then push it to the stack according to the arithmetic order
        if (tokens[i] == '+' || tokens[i] == '-' || tokens[i] == '/' || tokens[i] == '*') {
            addAnArithmetic(&operatorStack, &finalStack, tokens[i]);
            i++;
            //if it is a digit, read all of the digits that comes after, then push the number to the stack
        } else if ((isdigit(tokens[i])) || tokens[i]=='.') {
            string word="";
            // There may be more than one digits in number.
            while ((i < tokens.length()) && ((isdigit(tokens[i])) || tokens[i]=='.')) {
                word+=tokens[i];
                i++;
            }
            finalStack.push(word);
            //if it's a left brace, push it to the operator stack
        } else if (tokens[i] == '(') {
            operatorStack.push(tokens[i]);
            i++;
            //if it is a right brace, push out all the items untill raching "("
        } else if (tokens[i] == ')') {
            i++;
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                refeal(&operatorStack,&finalStack);
            }
            //take out the last thing left - the open brace (
            operatorStack.pop();
            //it is a variable
        } else {
            string variable="";
            while(tokens[i]!='(' && tokens[i]!=')' && tokens[i]!='+' && tokens[i]!='-' && tokens[i]!='*'
            && tokens[i]!='/' && tokens[i]!='\0') {
                variable+=tokens[i];
                i++;
            }
            if(this->valMap->count(variable)==0) {
                throw logic_error("No such variable"+variable);
            } else {
                finalStack.push(to_string(this->valMap->at(variable)));
            }

        }
    }
    //push out all the items that are left.
    while (!operatorStack.empty()) {
        refeal(&operatorStack,&finalStack);
    }

    Expression* result=calculate(&finalStack);
    return result->evaluate();
}


//take a char out of the stack of the operators and put it into the stack
void ShuntingYard::refeal(stack<char> *operatorStack, stack<string> *finalStack) {
    char op = operatorStack->top();
    operatorStack->pop();
    string opStr;
    opStr.push_back(op);
    finalStack->push(opStr);
}

/*push a (+ - * / ) to the stack, if on the top there is another operator that has to come first, take
it out and push it to the stack*/
void ShuntingYard::addAnArithmetic(stack<char> *operatorStack, stack<string> *finalStack, char act) {

    if (!operatorStack->empty()) {
        char last = (operatorStack->top());
        if (precedence(last) > precedence(act)) {
            string opStr;
            opStr.push_back(last);
            finalStack->push(opStr);
            operatorStack->pop();
        }
    }
    operatorStack->push(act);
}


//--telnet=socket,in,10,127.0.0.1,5402,tcp‬‬ --httpd=8080

//recursive function to make the stack an Expression
Expression* ShuntingYard::calculate(stack<string> *finalStack) {
    map<string,Expression*> arithmeticMap={{"+",new Plus()},{"-",new Minus()},{"/",new Divide},{"*",new Multiply}};
    string current=finalStack->top();
    Expression *expression;
    if (current == "+" || current == "-" || current == "/" || current == "*") {
        expression=arithmeticMap.at(current);
        finalStack->pop();
        expression->setValues(calculate(finalStack),calculate(finalStack));
        return expression;
    } else {
        expression=new Number(current);
        finalStack->pop();
        return expression;
    }
}