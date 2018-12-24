//
// Created by user on 24/12/18.
//



#include <thread>
#include "SleepCommand.h"
#include "ShuntingYard.h"

SleepCommand::SleepCommand(map<string, double> *varMap, vector<string>::iterator *it, map<string, double &> *bindMap) {
    this->bindMap = bindMap;
    this->it = it;
    this->varMap = varMap;

}

double SleepCommand::excecute() {
    (*it)++;
    Expression *e;
    e = new ShuntingYard(this->varMap, (it), bindMap);
    double val = e->evaluate();
    double divide = val / 1000;
    std::this_thread::sleep_for(std::chrono::milliseconds(int(divide)));
    return divide; ///?
}
