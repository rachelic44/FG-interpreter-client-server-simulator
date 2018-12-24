//
// Created by user on 18/12/18.
//

#ifndef PROJECT_EXPRESSIONFACTORY_H
#define PROJECT_EXPRESSIONFACTORY_H


#include <string>
#include "Expression.h"
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
};


#endif //PROJECT_EXPRESSIONFACTORY_H
