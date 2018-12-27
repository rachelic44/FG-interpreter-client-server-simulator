/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

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
    return 0;
}
