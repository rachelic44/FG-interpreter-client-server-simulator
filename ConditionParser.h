//
// Created by user on 19/12/18.
//

#ifndef PROJECT_CONDITIONPARSER_H
#define PROJECT_CONDITIONPARSER_H


#include "Command.h"
#include <vector>
#include <stdio.h>
#include <map>

using namespace std;

class ConditionParser : public Command {
protected:
    vector<Command*> commandVector;
    bool happens;
    map<string,double&>* bindMap;
    map<string,double >* varMap;
    vector<string>::iterator* it;

public:
    ConditionParser(map<string,double >* varMap,vector<string>::iterator* it,map<string,double&>* bindMap);
    double excecute();
    vector<Command*> getCommand() {
        return this->commandVector;
    }
    bool calculateHappens(int *);
    string sub(string,int,int);
    int findS(string,string);
};


#endif //PROJECT_CONDITIONPARSER_H
