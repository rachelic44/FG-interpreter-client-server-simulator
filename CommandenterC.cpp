//
// Created by user on 23/12/18.
//

#include "CommandenterC.h"
#include <iostream>
using namespace std;

CommandenterC::CommandenterC(vector<string>::iterator* it) {
    this->it=it;
}
double CommandenterC::excecute() {
    char c;
    cin>>c;
    (*it)++;
    cout<<"was in enterc";
}