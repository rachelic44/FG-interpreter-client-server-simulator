//
// Created by user on 17/12/18.
//

#include "CommandVar.h"
#include "CommandAssign.h"
#include "ShuntingYard.h"
#include "ExpressionFactory.h"

CommandVar::CommandVar(  map<string,double >* varMap,vector<string>::iterator* iterator1) {
    this->it=iterator1;
    this->varMap=varMap;
}



double CommandVar::excecute() {
    int index=0;
    //to avoid the "var", put the value into var
    (*it)++;
    string var=(*(*it));
    //"reach the "=""
    (*it)++; index++;

    if((*(*it))!="=") {
        throw logic_error("missing a '=' operator"); //todo check "var x;"
    }
    //go to the expresion comes after the =
    (*it)++; index++;




    ExpressionFactory expressionFactory(this->varMap,it);

    Expression* exp=new ShuntingYard(this->varMap,it);
    double value=expressionFactory.create(*(*it))->evaluate();
    if(this->varMap->count(var) == 0) {
        this->varMap->insert({var,value});
    } else {
        this->varMap->at(var)=value;
    }
    return index;
}