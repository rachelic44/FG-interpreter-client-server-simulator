//
// Created by user on 17/12/18.
//

#ifndef PROJECT_COMMANDASSIGN_H
#define PROJECT_COMMANDASSIGN_H

#include "Command.h"
#include "map"
#include "vector"
using namespace std;

class CommandAssign: public Command {

private:
    map<string,double >* varMap;
    vector<string>::iterator* it;
    map<string,double&>* bindMap;

public:
    CommandAssign(map<string,double >* varMap,vector<string>::iterator*, map<string,double&>*);
    virtual double excecute ();
};


#endif //PROJECT_COMMANDASSIGN_H
