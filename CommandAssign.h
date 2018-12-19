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

public:
    CommandAssign(map<string,double >* varMap,vector<string>::iterator*);
    virtual double excecute ();
};


#endif //PROJECT_COMMANDASSIGN_H
