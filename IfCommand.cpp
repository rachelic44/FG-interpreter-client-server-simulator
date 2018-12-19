//
// Created by user on 19/12/18.
//

#include <iostream>
#include "IfCommand.h"


double IfCommand::excecute() {
    ExpressionFactory expressionFactory(this->varMap,it);
    if(this->calculateHappens()) {
        while( (**it)!="}") {
            expressionFactory.create(**it)->evaluate();
        }
    }
    (*it)++;
  //  cout<<(**it);
    (*it)++;
}