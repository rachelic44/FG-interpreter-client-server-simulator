//
// Created by user on 23/12/18.
//

#ifndef PROJECT_BINDCOMMAND_H
#define PROJECT_BINDCOMMAND_H

#include <map>
#include <vector>
#include "Command.h"

using namespace std;

class BindCommand : public Command{
private:
    map<string,double >* varMap;
    vector<string>::iterator* it;
    map<string,double&>* bindMap;

public:
    BindCommand(map<string,double >* varMap,vector<string>::iterator*, map<string,double&>*);
    virtual double excecute ();
};


#endif //PROJECT_BINDCOMMAND_H
