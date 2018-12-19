//
// Created by user on 19/12/18.
//

#include <iostream>
#include "IfCommand.h"


double IfCommand::excecute() {
    int index=0;
    ExpressionFactory expressionFactory(this->varMap,it);
    if(this->calculateHappens(&index)) {
        while( (**it)!="}") {
            index+=expressionFactory.create(**it)->evaluate();
        }
    }
    (*it)++; index++;
  //  cout<<(**it);
    (*it)++; index++;
    cout<<index;
    return index;
}