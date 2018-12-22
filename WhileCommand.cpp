//
// Created by user on 19/12/18.
//

#include <iostream>
#include "WhileCommand.h"



double WhileCommand::excecute() {
    int index=0; int pos=0;
    vector<string>::iterator last=(*it);
    ExpressionFactory expressionFactory(this->varMap,it);
    while(this->calculateHappens(&index)) {
        index=0;
        //last=(*it);
        while( (**it)!="}") {

            index += expressionFactory.create(**it)->evaluate();
        }
        (*it)=last;
        last=(*it);

    }
    while((**it)!="}" ) {
        (*it)++; index++;
    }
    //skip the }
    (*it)++; index++;

    if((**it)=="\n") {
        (*it)++;
        index++;
    }
    return index;
}