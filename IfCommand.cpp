//
// Created by user on 19/12/18.
//

#include <iostream>
#include "IfCommand.h"


double IfCommand::excecute() {
    int index=0;
    ExpressionFactory expressionFactory(this->varMap,it);
    if(this->calculateHappens(&index)) {
        cout<<endl<<index<<endl;
        while( (**it)!="}") {
            if (expressionFactory.create(**it) == NULL) {
                index+=expressionFactory.create("=")->evaluate();
            } else {
                index += expressionFactory.create(**it)->evaluate();
            }
        }
    } else {
        cout<<endl<<index<<endl;
        while((**it)!="}" ) {
            (*it)++; index++;
        }
    }
    (*it)++; index++;
  //  cout<<(**it);
    (*it)++; index++;
    cout<<index;
    return index;
}