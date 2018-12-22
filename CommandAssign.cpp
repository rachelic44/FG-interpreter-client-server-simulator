//
// Created by user on 17/12/18.
//

#include "CommandAssign.h"
#include "ShuntingYard.h"
#include "ExpressionFactory.h"

CommandAssign::CommandAssign(map<string,double >* varMap,vector<string>::iterator* it) {
    this->it=it;
    this->varMap=varMap;
}

double CommandAssign::excecute() {

    int index=0;
    string var=*(*it);
    if(this->varMap->count(var)==0) {
        __throw_logic_error("no such variable was declared");//
    }
    (*it)++;
    if((*(*it))!="=") {
        __throw_logic_error("no = operator");//todo change - checkt no other cases? must throw?
    }
    (*it)++;
    ExpressionFactory expressionFactory(this->varMap,it);
    double value=expressionFactory.create(*(*it))->evaluate();
    this->varMap->at(var)=value;
    return index;

}