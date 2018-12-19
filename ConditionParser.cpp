//
// Created by user on 19/12/18.
//

#include "ConditionParser.h"
#include "ShuntingYard.h"

ConditionParser::ConditionParser(map<string,double >* varMap,vector<string>::iterator* it) {
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

bool ConditionParser::calculateHappens() {
    if ((**it) != "while" && (**it) != "if") {
        __throw_logic_error("missing while or if");
    }
    (*it)++;
    string exp1 = "", first, second;
    while ((**it) != "{") {
        if((**it) != "\n") {
            exp1 += (**it);
        }
        (*it)++;
    }

    (*it)++;
    if((**it) == "\n") {
        (*it)++;
    }

    int found = 0, sign = 0, i = 0;
    string operat;
    Expression *expression1;
    Expression *expression2;
    vector<string> operatorsVec = {"<=", ">=", "<", ">", "!=", "=="};
    while (i < 6) {
        operat = operatorsVec.at(i);
        if (findS(exp1,operat)>=0) {
            found = findS(exp1,operat);
            first = sub(exp1, 0, found);
            second = sub(exp1, found + operat.length(), exp1.length());
            expression1 = new ShuntingYard(this->varMap, first);
            expression2 = new ShuntingYard(this->varMap, second);
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

    if((**it) == "\n") {
        (*it)++;
    }
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

