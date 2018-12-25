//
// Created by user on 17/12/18.
//

#include "CommandAssign.h"
#include "ShuntingYard.h"
#include "ExpressionFactory.h"
#include "DictionaryPath.h"
#include "BoundMap.h"
#include "ConnectCommand.h"
CommandAssign::CommandAssign(map<string,double >* varMap,vector<string>::iterator* it, map<string,double&>* bindMap,
        ExpressionFactory* expressionFactory) {
    this->expressionFactory=expressionFactory;
    this->bindMap=bindMap;
    this->it=it;
    this->varMap=varMap;
}

double CommandAssign::excecute() {

    string var=*(*it);
    if(this->varMap->count(var)==0 && this->bindMap->count(var)==0) {
        __throw_logic_error("no such variable was declared");
    }
    (*it)++;
    if((*(*it))!="=") {
        __throw_logic_error("no = operator");
    }
    (*it)++;

    map<string,double >* dictionary=DictionaryPath::instance()->getMap();
    map<string,string>* bounded=BoundMap::instance()->getMap();



    double value=this->expressionFactory->create(*(*it))->evaluate();

    if(this->bindMap->count(var)>0) {
        if(dictionary->count(bounded->at(var))>0) { //call the client t write it
            this->bindMap->at(var)=value;
            ConnectCommand::writeFunc(bounded->at(var));
        } else if(this->varMap->count(bounded->at(var))>0){
            this->bindMap->at(var)=value;
        }
    } else {
        if(this->varMap->count(var) == 0 ){
            throw logic_error("there is no such variable");
        }
        this->varMap->at(var)=value; //not supposed to reach here, it is assign.
    }
    int yy =5;

}