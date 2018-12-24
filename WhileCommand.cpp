//
// Created by user on 19/12/18.
//

#include <iostream>
#include "WhileCommand.h"



double WhileCommand::excecute() {
    int index=0; int pos=0;
    vector<string>::iterator last=(*it);
    vector<string>::iterator p;
    while(this->calculateHappens(&index)) {
        index=0;
        //last=(*it);
        while( (**it)!="}") {
            string w=(**it);
            index += this->expressionFactory->create(**it)->evaluate();
        }
        p=(*it);
        (*it)=last;
        last=(*it);

    }
    //the condition does not happen, so t=now the iterator is in the same place where it stopped
    (*it)=p;
    //skip the }
    (*it)++; index++;

    if((**it)=="\n") { //todo not needed
        (*it)++;
        index++;
    }
    return index;
}