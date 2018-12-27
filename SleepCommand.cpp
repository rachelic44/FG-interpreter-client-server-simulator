//
// Created by user on 24/12/18.
//



#include <thread>
#include <unistd.h>
#include "SleepCommand.h"
#include "ShuntingYard.h"


SleepCommand::SleepCommand(map<string, double> *varMap, vector<string>::iterator *it, map<string, double &> *bindMap) {
    this->bindMap = bindMap;
    this->it = it;
    this->varMap = varMap;

}

double SleepCommand::excecute() {
    (*it)++;
    Expression *e = new ShuntingYard(this->varMap, it, bindMap);
    int val = e->evaluate();
    delete e;
    sleep(val/1000);

}
