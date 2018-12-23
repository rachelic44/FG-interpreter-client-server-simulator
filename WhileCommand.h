//
// Created by user on 19/12/18.
//

#ifndef PROJECT_WHILECOMMAND_H
#define PROJECT_WHILECOMMAND_H



#include "Command.h"
#include "ConditionParser.h"
#include "iostream"
#include "ExpressionFactory.h"

using namespace std;

class WhileCommand : public ConditionParser {
public:
    WhileCommand(map<string,double >* varMap,vector<string>::iterator* it,map<string,double&>* bindMap)
    : ConditionParser(varMap,it,bindMap){}
    double excecute();
};



#endif //PROJECT_WHILECOMMAND_H
