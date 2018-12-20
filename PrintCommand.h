

#ifndef PROJECT_PRINTCOMMANDER_H
#define PROJECT_PRINTCOMMANDER_H

#include "Command.h"
#include "iostream"
#include "ExpressionFactory.h"
#include <string>

using namespace std;

class PrintCommand : public Command  {
private:
    map<string,double >* varMap;
    vector<string>::iterator* it;
public:
    PrintCommand(map<string,double >* varMap,vector<string>::iterator* it);
    double excecute() override;
};



#endif //PROJECT_PRINTCOMMANDER_H
