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

    int index=0;
    string var=*(*it);
    if(this->varMap->count(var)==0) {
        __throw_logic_error("no such variable was declared");//todo change
    } else {
        (*it)+=2;  index+=2;
        string expressionToBe=(*(*it));
        (*it)++;  index++;
        while((*(*it))!="\n") {
            if(((*(*it))!="{")) {
                expressionToBe += (*(*it));
                (*it)++;
                index++;
            }
        }
        //skip on the \n
        (*it)++;  index++;
        Expression* exp=new ShuntingYard(this->varMap,expressionToBe);
        double value=exp->evaluate();
        this->varMap->at(var)=value;
    }
    return index;

}