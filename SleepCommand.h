/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#ifndef PROJECT_SLEEPCOMMAND_H
#define PROJECT_SLEEPCOMMAND_H


#include "Command.h"
#include "ConditionParser.h"
#include "iostream"
#include "ExpressionFactory.h"
using namespace std;

class SleepCommand : public Command {
private:
    map<string,double >* varMap;
    vector<string>::iterator* it;
    map<string,double&>* bindMap;

public:
    SleepCommand(map<string,double >* varMap,vector<string>::iterator* it,map<string,double&>* bindMap);
    double excecute();
};



#endif //PROJECT_SLEEPCOMMAND_H
