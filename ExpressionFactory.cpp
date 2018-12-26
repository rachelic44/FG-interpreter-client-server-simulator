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
#include "ConnectCommand.h"
#include "SleepCommand.h"

ExpressionFactory::ExpressionFactory(map<string, double> *varMap, vector<string>::iterator *it,
                                     map<string, double &>* bindMap,pthread_cond_t* cond, pthread_mutex_t* mutex) {
    this->bindMap = bindMap;
    this->varMap = varMap;
    this->it = it;
    this->mutex=mutex;
    this->cond=cond;

}

Expression *ExpressionFactory::create(string word) {
    if (word == "var") {
        Command* com=new CommandVar(varMap, it, bindMap,this);
        Expression* expressionToReturn=new ExpressionCommand(com);
        this->vecToReleaseMemory.push_back(expressionToReturn);
        this->vecToRelaseCommands.push_back(com);
        return expressionToReturn;
    }
    if (word == "if") {
        Command* com=new IfCommand(varMap, it, bindMap,this);
        Expression* expressionToReturn=new ExpressionCommand(com);
        this->vecToReleaseMemory.push_back(expressionToReturn);
        this->vecToRelaseCommands.push_back(com);
        return expressionToReturn;
    }
    if (word == "while") {
        Command* com=new WhileCommand(varMap, it, bindMap,this);
        Expression* expressionToReturn=new ExpressionCommand(com);
        this->vecToReleaseMemory.push_back(expressionToReturn);
        this->vecToRelaseCommands.push_back(com);
        return expressionToReturn;
    }
    if (word == "print") {
        Command* com=new PrintCommand(varMap, it, bindMap);
        Expression* expressionToReturn=new ExpressionCommand(com);
        this->vecToReleaseMemory.push_back(expressionToReturn);
        this->vecToRelaseCommands.push_back(com);
        return expressionToReturn;
    }
    if (((this->varMap->count(word) > 0) || this->bindMap->count(word) > 0) && ((*((*it) + 1)) == "=")) { //todo U
        Command* com=new CommandAssign(varMap, it, bindMap,this);
        Expression* expressionToReturn=new ExpressionCommand(com);
        this->vecToRelaseCommands.push_back(com);
        this->vecToReleaseMemory.push_back(expressionToReturn);
        return expressionToReturn;
    }
    if(word=="bind") {
        Command* com=new BindCommand(varMap, it, bindMap);
        Expression* expressionToReturn=new ExpressionCommand(com);
        this->vecToReleaseMemory.push_back(expressionToReturn);
        this->vecToRelaseCommands.push_back(com);
        return expressionToReturn;
    }
    if(word=="enterc") {
        cout<<"----connecetd0";
        Command* com=new CommandenterC(it);
        Expression* expressionToReturn=new ExpressionCommand(com);
        this->vecToReleaseMemory.push_back(expressionToReturn);
        this->vecToRelaseCommands.push_back(com);
        return expressionToReturn;
    }
    if(word=="openDataServer") {
        Command* com=new OpenDataServerCommand(varMap, it, bindMap,this);
        Expression* expressionToReturn=new ExpressionCommand(com);
        this->vecToReleaseMemory.push_back(expressionToReturn);
        this->vecToRelaseCommands.push_back(com);
        return expressionToReturn;
    }
    if(word=="connect") {
       // cout<<"connecetd0"; todo check - came here too many times
       Command* com =new ConnectCommand(varMap, it, bindMap,this);
        Expression* expressionToReturn=new ExpressionCommand(com);
        this->vecToReleaseMemory.push_back(expressionToReturn);
        this->vecToRelaseCommands.push_back(com);
        return expressionToReturn;
    }
    if(word=="sleep") {
        Command* com=new SleepCommand(varMap, it, bindMap);
        Expression* expressionToReturn=new ExpressionCommand(com);
        this->vecToReleaseMemory.push_back(expressionToReturn);
        this->vecToRelaseCommands.push_back(com);
        return expressionToReturn;
    }
    Expression* expressionToReturn=new ShuntingYard(varMap, it, bindMap);
    this->vecToReleaseMemory.push_back(expressionToReturn);
    return expressionToReturn;

    //chack todo if it is a null - then it is supposed to ba a line starts with variable
}