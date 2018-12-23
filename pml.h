//
// Created by user on 23/12/18.
//

#ifndef PROJECT_PML_H
#define PROJECT_PML_H

#include <map>
#include "DictionaryPath.h"

using namespace std;

class pml {

private:
    map<string,int> m;
public:
    pml() {
        m.insert({"a",6});
    }
    map<string,int>* getmap() {
        DictionaryPath dictionaryPath;
        dictionaryPath.instance()->getMap()->insert({"b",2});
        return &this->m;
    }
};


#endif //PROJECT_PML_H
