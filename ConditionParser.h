/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#ifndef PROJECT_CONDITIONPARSER_H
#define PROJECT_CONDITIONPARSER_H


#include "Command.h"
#include <vector>
#include <stdio.h>
#include <map>
#include "ExpressionFactory.h"
using namespace std;

class ConditionParser : public Command {
protected:
    vector<Command*> commandVector;
    bool happens;
    map<string,double&>* bindMap;
    map<string,double >* varMap;
    vector<string>::iterator* it;
    ExpressionFactory* expressionFactory;

public:
    ConditionParser(map<string,double >* varMap,vector<string>::iterator* it,map<string,double&>* bindMap
    ,ExpressionFactory* expressionFactory);
    double excecute();
    vector<Command*> getCommand() {
        return this->commandVector;
    }
    bool calculateHappens(int *);
    string sub(string,int,int);
    int findS(string,string);
};


#endif //PROJECT_CONDITIONPARSER_H
