//
// Created by user on 23/12/18.
//

#ifndef PROJECT_COMMANDENTERC_H
#define PROJECT_COMMANDENTERC_H


#include "Command.h"
#include <iostream>
#include <vector>
using namespace std;


class CommandenterC : public Command {
private:
    vector<string>::iterator* it;
public:
    CommandenterC(vector<string>::iterator* it);
    virtual double excecute ();
};


#endif //PROJECT_COMMANDENTERC_H
