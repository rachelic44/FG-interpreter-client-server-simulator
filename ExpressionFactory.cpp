//
// Created by user on 18/12/18.
//

#include "ExpressionFactory.h"
#include "ExpressionCommand.h"
#include "CommandVar.h"
#include "CommandAssign.h"
#include "IfCommand.h"
#include "WhileCommand.h"

ExpressionFactory::ExpressionFactory(map<string, double> *varMap, vector<string>::iterator* it) {
    this->varMap=varMap;
    this->it=it;
}
Expression* ExpressionFactory::create(string word) {
    if(word=="var") {
        return new ExpressionCommand(new CommandVar(varMap,it));
    }
    if(word=="=") {
        return new ExpressionCommand(new CommandAssign(varMap,it));
    }
    if(word=="if") {
        return new ExpressionCommand(new IfCommand(varMap,it));
    }
    if(word=="while") {
        return new ExpressionCommand(new WhileCommand(varMap,it));
    }
    return NULL; //chack todo if it is a null - then it is supposed to ba a line starts with variable
}