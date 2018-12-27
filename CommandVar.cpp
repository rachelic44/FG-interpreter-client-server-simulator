/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */
#include "CommandVar.h"
#include "CommandAssign.h"
#include "ShuntingYard.h"
#include "ExpressionFactory.h"
#include "DictionaryPath.h"
#include "BoundMap.h"
#include "BindCommand.h"

CommandVar::CommandVar(  map<string,double >* varMap,vector<string>::iterator* iterator1, map<string,double&>* bindMap,
        ExpressionFactory* expressionFactory) {
    this->expressionFactory=expressionFactory;
    this->it=iterator1;
    this->varMap=varMap;
    this->bindMap=bindMap;
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




   // Expression* exp=new ShuntingYard(this->varMap,it,bindMap); not needed
    double value=this->expressionFactory->create(*(*it))->evaluate();
    if(this->varMap->count(var) == 0 && this->bindMap->count(var) ==0) {
        this->varMap->insert({var,value}); //enter only if the parameter doesnt exist already (if it does,
        // bind happened) //todo check. supposed to be ok cause we were told there wont be two declerartions.
    }
    return index;
}