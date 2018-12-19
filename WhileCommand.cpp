//
// Created by user on 19/12/18.
//

#include <iostream>
#include "WhileCommand.h"



double WhileCommand::excecute() {
    int index=0; int pos=0;
    ExpressionFactory expressionFactory(this->varMap,it);
    while(this->calculateHappens(&index)) {
        while( (**it)!="}") {
            if (expressionFactory.create(**it) == NULL) {
                index+=expressionFactory.create("=")->evaluate();
            } else {
                index += expressionFactory.create(**it)->evaluate();
            }
        }
        (*it)-=index;

    }
    while((**it)!="}" ) {
        (*it)++; index++;
    }
    //to avoid the \n
    (*it)++; index++;
    //  cout<<(**it);
    (*it)++; index++;
    cout<<index;
    return index;
}