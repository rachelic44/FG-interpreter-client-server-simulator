/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */
#ifndef PROJECT_EXPRESSIONFACTORY_H
#define PROJECT_EXPRESSIONFACTORY_H


#include <string>
#include "Expression.h"
#include "Command.h"
#include <map>
#include <vector>

using namespace std;

class ExpressionFactory {

private:
    map<string,double&>* bindMap;
    map<string,double >* varMap;
    vector<string>::iterator* it;
    pthread_cond_t* cond;
    pthread_mutex_t* mutex;
    vector<Expression*> vecToReleaseMemory;
    vector<Command*> vecToRelaseCommands;
public:
    ExpressionFactory(map<string,double >* varMap, vector<string>::iterator* it,map<string,double&>* bindMap
    ,pthread_cond_t* cond, pthread_mutex_t* mutex);
    Expression* create(string word);
    pthread_mutex_t* getMutix() {
        return this->mutex;
    }
    pthread_cond_t* getCond() {
        return this->cond;
    }
    ~ExpressionFactory() {
        for(Command* command: this->vecToRelaseCommands) {
           delete command;
        }
        for(Expression* expression : this->vecToReleaseMemory) {
            delete expression;
        }
    }
};


#endif //PROJECT_EXPRESSIONFACTORY_H
