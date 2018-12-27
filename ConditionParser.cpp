//
// Created by user on 19/12/18.
//

#include "ConditionParser.h"
#include "ShuntingYard.h"

ConditionParser::ConditionParser(map<string,double >* varMap,vector<string>::iterator* it,map<string,double&>* bindMap
        ,ExpressionFactory* expressionFactory) {
    this->expressionFactory=expressionFactory;
   this->bindMap=bindMap;
    this->it=it;
    this->varMap=varMap;
}

string ConditionParser::sub(string str, int start, int end) {
    string strToBe = "";
    int i = 0;
    for (i = start; i < end; i++) {
        strToBe += str[i];
    }
    return strToBe;
}


double ConditionParser::excecute() {

}

bool ConditionParser::calculateHappens(int * index) {
    if ((**it) != "while" && (**it) != "if") {
        __throw_logic_error("missing while or if");
    }
    (*it)++; (*index)++;
    string exp1 = "", first, second;
    while ((**it) != "{") {
        exp1 += (**it);
        (*it)++; (*index)++;
    }

    (*it)++; (*index)++;


    int found = 0, sign = 0, i = 0;
    string operat;
    Expression *expression1;
    Expression *expression2;
    vector<string> operatorsVec = {"<=", ">=", "<", ">", "!=", "=="};
    vector<string> meanWhile;
    vector<string>::iterator itWhile;
    vector<string> meanWhile2;
    vector<string>::iterator itWhile2;
    while (i < 6) {
        operat = operatorsVec.at(i);
        if (findS(exp1,operat)>=0) {
            found = findS(exp1,operat);
            first = sub(exp1, 0, found);
            meanWhile.push_back(first);
            meanWhile.push_back("\n");
            itWhile=meanWhile.begin();
            second = sub(exp1, found + operat.length(), exp1.length());
            meanWhile2.push_back(second);
            meanWhile2.push_back("\n");
            itWhile2=meanWhile2.begin();
            expression1 = new ShuntingYard(this->varMap, &itWhile,bindMap);
            expression2 = new ShuntingYard(this->varMap, &itWhile2,bindMap);
            sign++;
            break;
        }
        i++;
    }
    if(!(sign)) {
        __throw_logic_error("if/while statement without opertor");
    }
    double expression1V=expression1->evaluate();
    double expression2V=expression2->evaluate();
    if(operat=="<=" && (expression1V<=expression2V)) {
        this->happens= true;
    } else if(operat==">=" && (expression1V>=expression2V)) {
        this->happens = true;
    } else if(operat=="<" && (expression1V<expression2V)) {
        this->happens = true;
    } else if(operat==">" && (expression1V>expression2V)) {
        this->happens = true;
    } else if(operat=="!=" && (expression1V!=expression2V)) {
        this->happens = true;
    } else if(operat=="==" && (expression1V==expression2V)) {
        this->happens = true;
    } else {
        this->happens = false;
    }


    delete expression1;
    delete expression2;
    return this->happens;
}

int ConditionParser::findS(string word, string f) {
    int j=0;
    for(int i=0;i<word.length();i++) {
        if(word[i]==f[j]) {
            if(f.length()==2) {
                if(word[i+1]!=f[j+1]) {
                    return -1;
                } else {
                    return i;
                }
            } else {
                return i;
            }
        }
    }
    return -1;
}

