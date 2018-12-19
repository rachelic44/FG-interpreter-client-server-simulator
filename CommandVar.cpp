//
// Created by user on 17/12/18.
//

#include "CommandVar.h"
#include "CommandAssign.h"
#include "ShuntingYard.h"

CommandVar::CommandVar(  map<string,double >* varMap,vector<string>::iterator* iterator1) {
    this->it=iterator1;
    this->varMap=varMap;
}

bool func1(string next) {
    if(next[0]=='*' || next[0]=='-' || next[0]=='+' || next[0]=='/') {
        return true;
    }
    return false;
}

bool func2(string& next) {
    if(next[next.length()-1] =='+' ||next[next.length()-1] =='-' ||next[next.length()-1] =='*'
       ||next[next.length()-1] =='/' ) {
        return true;
    }
    return false;
}

double CommandVar::excecute() {
    int index=0;
    //to avoid the "var", put the value into var
    (*it)++; index++;
    string var=(*(*it));
    //"reach the "+""
    (*it)++; index++;

    if((*(*it))!="=") {
        throw logic_error("missing a '=' operator"); //todo check "var x;"
    }
    (*it)++; index++;

    //now - avoiding the spaces  that might have separated - reunion it to one string
    string expressionToBe=(*(*it));
    (*it)++; index++;
    while((*(*it))!="\n") {
        expressionToBe+=(*(*it));
        (*it)++; index++;
    }
    //skip on the \n
    (*it)++;  index++;

    Expression* exp=new ShuntingYard(this->varMap,expressionToBe);
    double value=exp->evaluate();
    this->varMap->insert({var,value});
    return index;
}