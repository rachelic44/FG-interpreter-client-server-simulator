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
public:
    ExpressionFactory(map<string,double >* varMap, vector<string>::iterator* it,map<string,double&>* bindMap);
    Expression* create(string word);
};


#endif //PROJECT_EXPRESSIONFACTORY_H
