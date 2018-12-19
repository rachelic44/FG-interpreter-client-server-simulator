//
// Created by user on 19/12/18.
//

#include <iostream>
#include "WhileCommand.h"



double WhileCommand::excecute() {
    int index=0; int pos=0;
    ExpressionFactory expressionFactory(this->varMap,it);
    while(this->calculateHappens(&index)) {
        pos=index;
        while( (**it)!="}") {
            index+=expressionFactory.create(**it)->evaluate();
        }
        index+=(index-pos);

    }
    while((**it)!="}" ) {
        (*it)++; index++;
    }
    (*it)++; index++;
    //  cout<<(**it);
    (*it)++; index++;
    cout<<index;
    return index;
}