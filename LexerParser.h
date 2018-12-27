/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#ifndef PROJECT_LEXERPARSER_H
#define PROJECT_LEXERPARSER_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;
//bool toChange=false;
class LexerParser {

private:
    map<string,double > varMap;
    map<string,double&> bindMap;
    vector<string> lexeredWord;

public:
    vector<string> splitter(string);
    void parser(vector <string> stringVector);

    map<string,double >* getVarMap() {
        /*for(auto& sm: bindMap) {
            varMap.insert(sm);
        }*/
        return &this->varMap;
    }
    map<string,double&>* getBindMap() {
        return &this->bindMap;
    }
    vector<string> getLexeredWord() {
        return this->lexeredWord;
    }
};


#endif //PROJECT_LEXERPARSER_H
