//
// Created by user on 19/12/18.
//

#ifndef PROJECT_IFCOMMAND_H
#define PROJECT_IFCOMMAND_H


#include "Command.h"
#include "ConditionParser.h"
#include "ExpressionFactory.h"

class IfCommand : public ConditionParser {
public:
    IfCommand(map<string,double >* varMap,vector<string>::iterator* it,map<string,double&>* bindMap
            ,ExpressionFactory* expressionFactory)
        : ConditionParser(varMap,it,bindMap,expressionFactory){}
    double excecute();
};


#endif //PROJECT_IFCOMMAND_H
