//
// Created by user on 23/12/18.
//

#include "BindCommand.h"
#include "DictionaryPath.h"
#include "BoundMap.h"

BindCommand::BindCommand(map<string, double> *varMap1, vector<string>::iterator * iterator1, map<string, double &>* bindMap1) {
    this->it=iterator1;
    this->varMap=varMap1;
    this->bindMap=bindMap1;
}

double BindCommand::excecute() {

    map<string,double >* dictionary=DictionaryPath::instance()->getMap();
    map<string,string>* bounded=BoundMap::instance()->getMap();

    string var=*((*it)-2);
    //go over the "bind" to the path/variavble
    (*it)++;
    string varToBePathTo=(**it);
    if(varToBePathTo[0]=='\"') {
        varToBePathTo.erase(0,1);
    }
    if(varToBePathTo[varToBePathTo.length()-1]=='\"') {
        varToBePathTo.erase(varToBePathTo.length()-1,1);
    }
    //if the bind is to a path
    if(dictionary->count((varToBePathTo))>0) {
        this->bindMap->insert({var,dictionary->at(varToBePathTo)});
        bounded->insert({var,varToBePathTo});

    } else { //if its not there also, throw
        this->bindMap->insert({var,this->varMap->at(varToBePathTo)});
        bounded->insert({var,varToBePathTo});
    }
    (*it)++;
}