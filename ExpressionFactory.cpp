//
// Created by user on 18/12/18.
//

#include "ExpressionFactory.h"
#include "ExpressionCommand.h"
#include "CommandVar.h"
#include "CommandAssign.h"
#include "IfCommand.h"
#include "WhileCommand.h"
#include "PrintCommand.h"
#include "ShuntingYard.h"
#include "BindCommand.h"
#include "CommandenterC.h"
#include "OpenDataServerCommand.h"


ExpressionFactory::ExpressionFactory(map<string, double> *varMap, vector<string>::iterator *it,
                                     map<string, double &>* bindMap) {
    this->bindMap = bindMap;
    this->varMap = varMap;
    this->it = it;
}

Expression *ExpressionFactory::create(string word) {
    if (word == "var") {
        return new ExpressionCommand(new CommandVar(varMap, it, bindMap));
    }
    if (word == "if") {
        return new ExpressionCommand(new IfCommand(varMap, it, bindMap));
    }
    if (word == "while") {
        return new ExpressionCommand(new WhileCommand(varMap, it, bindMap));
    }
    if (word == "print") {
        return new ExpressionCommand(new PrintCommand(varMap, it, bindMap));
    }
    if (((this->varMap->count(word) > 0) || this->bindMap->count(word) > 0) && ((*((*it) + 1)) == "=")) { //todo U
        return new ExpressionCommand(new CommandAssign(varMap, it, bindMap));
    }
    if(word=="bind") {
        return new ExpressionCommand(new BindCommand(varMap, it, bindMap));
    }
    if(word=="enterc") {
        return new ExpressionCommand(new CommandenterC(it));
    }
    if(word=="openDataServer") {
        return new ExpressionCommand(new OpenDataServerCommand(varMap, it, bindMap));
    }
    return new ShuntingYard(varMap, it, bindMap);

    //chack todo if it is a null - then it is supposed to ba a line starts with variable
}