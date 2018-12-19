//
// Created by user on 17/12/18.
//

#include "CommandAssign.h"
#include "ShuntingYard.h"

CommandAssign::CommandAssign(map<string,double >* varMap,vector<string>::iterator* it) {
    this->it=it;
    this->varMap=varMap;
}

double CommandAssign::excecute() {

    string var=*(*it);
    if(this->varMap->count(var)==0) {
        __throw_logic_error("no such variable was declared");//todo change
    } else {
        (*it)+=2;
        string expressionToBe=(*(*it));
        (*it)++;
        while((*(*it))!="\n") {
            expressionToBe+=(*(*it));
            (*it)++;
        }
        //skip on the \n
        (*it)++;
        Expression* exp=new ShuntingYard(this->varMap,expressionToBe);
        double value=exp->evaluate();
        this->varMap->at(var)=value;
    }

}