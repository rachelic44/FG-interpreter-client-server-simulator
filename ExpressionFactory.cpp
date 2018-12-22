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
    if(word=="print") {
        return new ExpressionCommand(new PrintCommand(varMap,it));
    }
    if((this->varMap->count(word)>0) && ((*((*it)+1))=="=")) { //todo U
        return new ExpressionCommand(new CommandAssign(varMap,it));
    }

    return new ShuntingYard(varMap,it);

    //chack todo if it is a null - then it is supposed to ba a line starts with variable
}