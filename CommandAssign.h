/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#ifndef PROJECT_COMMANDASSIGN_H
#define PROJECT_COMMANDASSIGN_H

#include "Command.h"
#include "map"
#include "vector"
#include "ExpressionFactory.h"
using namespace std;

class CommandAssign: public Command {

private:
    map<string,double >* varMap;
    vector<string>::iterator* it;
    map<string,double&>* bindMap;
    ExpressionFactory* expressionFactory;

public:
    CommandAssign(map<string,double >* varMap,vector<string>::iterator*, map<string,double&>*
            ,ExpressionFactory* expressionFactory);
    virtual double excecute ();
};


#endif //PROJECT_COMMANDASSIGN_H
