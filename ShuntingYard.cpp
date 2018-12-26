//
// Created by user on 17/12/18.
//

#include "ShuntingYard.h"


ShuntingYard::ShuntingYard(map<string, double>* map1,vector<string>::iterator* it, map<string,double&>* bindMap) {
    this->it=it;
    this->bindMap=bindMap;
    this->valMap=map1;
    for(auto& sm: *bindMap) {
        this->valMapAll.insert(sm);
    }
    for(auto& sm: *map1) {
        this->valMapAll.insert(sm);
    }

}

/**
* This function is to decide which precedence is higher
* @param op op
* @return 0 for wrong input
*/
int ShuntingYard::precedence(char op) {
    if (op == '+' )
        return 1;
    if (op == '-' )
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

bool isOpenOperator(char next) {
    if(next=='*' || next=='-' || next=='+' || next=='/' || (next=='(')) {
        return true;
    }
    return false;
}

bool isLastOperator(char next) {
    if(next=='*' || next=='-' || next=='+' || next=='/' || next== ')') {
        return true;
    }
    return false;
}

string ShuntingYard::evaluateTokens(vector<string>::iterator *it) {
    string current=(*(*it));
    int keep=0;
    if(isOpenOperator(current[current.length()-1]) ) {
        keep++;
    } else {
        if((*((*it)+1))!="\n") {
            if(isLastOperator((*((*it)+1))[0])) {
                keep++;
            }
        }
    }
    while(keep) {
        keep=0;
        (*it)++;
        current+=(*(*it));
        if(isOpenOperator(current[current.length()-1]) ) {
            keep++;
        } else {
            if((*((*it)+1))!="\n") {
                if(isLastOperator((*((*it)+1))[0])) {
                    keep++;
                }
            }
        }

    }
    //go to nexkt, but dont include it
    (*it)++;
    return current;
}

/**
 * This function gets a string of tokens and put it into a stack and a stack accordong to "Shating "Yard Algorithm"
 * @param tokens string
 * @return the value
 */
double ShuntingYard::evaluate() {
    this->tokens=evaluateTokens(this->it);
    string tokens=this->tokens;
    stack<char> operatorStack;
    stack<string> finalStack;

    int i = 0, sign=0, keep=0;
    //go over the string
    while (i < tokens.length()) {
        //if it is (+ - / * ), then push it to the stack according to the arithmetic order
        if (tokens[i] == '+' || tokens[i] == '-' || tokens[i] == '/' || tokens[i] == '*') {
            if(tokens[i]=='-' && i==0) {
                sign++;
            } else if( tokens[i]=='-' && (tokens[i-1]=='-' ||tokens[i-1]=='*' ||tokens[i-1]=='/' ||tokens[i-1]=='+')) {
                sign++;
            }
            if(sign) {
                keep=i;
                tokens.insert(i,"(0");
                while(tokens[i+3] !='(' && tokens[i+3] !=')' && tokens[i+3] !='+' && tokens[i+3] !='-' &&
                      tokens[i+3] !='*' && tokens[i+3] !='/' && tokens[i+3] !='\0') {
                    i++;
                }
                tokens.insert(i+3,")");
                sign=0;
                i=keep;
                continue;
            }
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
            if(this->valMapAll.count(variable)==0) {
                throw logic_error("No such variable"+variable);
            } else {
                finalStack.push(to_string(this->valMapAll.at(variable)));
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
        while (precedence(last) >= precedence(act)) {
            string opStr;
            opStr.push_back(last);
            finalStack->push(opStr);
            operatorStack->pop();
            if(operatorStack->empty()) {
                break;
            }
            last = (operatorStack->top());
        }
    }
    operatorStack->push(act);
}


//--telnet=socket,in,10,127.0.0.1,5402,tcp‬‬ --httpd=8080

//recursive function to make the stack an Expression
Expression* ShuntingYard::calculate(stack<string> *finalStack) {
    Plus* plus=new Plus(); Multiply* multiply=new Multiply; Minus* minus=new Minus; Divide* divide=new Divide;
    this->vecToRelease.push_back(plus); this->vecToRelease.push_back(minus);
    this->vecToRelease.push_back(divide); this->vecToRelease.push_back(multiply);
    map<string,Expression*> arithmeticMap={{"+",plus},{"-",minus},{"/",divide},{"*",multiply}};

    string current=finalStack->top();
    Expression *expression;
    if (current == "+" || current == "-" || current == "/" || current == "*") {
        expression=arithmeticMap.at(current);
        finalStack->pop();
        expression->setValues(calculate(finalStack),calculate(finalStack));
        return expression;
    } else {
        Expression* num=new Number(current);
        this->vecToRelease.push_back(num);
        finalStack->pop();
        return num;
    }
}