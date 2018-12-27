/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#ifndef PROJECT_WHILECOMMAND_H
#define PROJECT_WHILECOMMAND_H



#include "Command.h"
#include "ConditionParser.h"
#include "iostream"
#include "ExpressionFactory.h"

using namespace std;

class WhileCommand : public ConditionParser {
public:
    WhileCommand(map<string,double >* varMap,vector<string>::iterator* it,map<string,double&>* bindMap
            ,ExpressionFactory* expressionFactory)
    : ConditionParser(varMap,it,bindMap ,expressionFactory){}
    double excecute();
};



#endif //PROJECT_WHILECOMMAND_H
