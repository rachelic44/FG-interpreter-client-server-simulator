//
// Created by user on 19/12/18.
//

#include <iostream>
#include "IfCommand.h"


double IfCommand::excecute() {
    int index=0;
    if(this->calculateHappens(&index)) {
        while( (**it)!="}") {
            string woird=(*(*it));
            if (this->expressionFactory->create(**it) == NULL) {
                index+=this->expressionFactory->create("=")->evaluate();
            } else {
                index += this->expressionFactory->create(**it)->evaluate();
            }
        }
    } else {
        cout<<endl<<index<<endl;
        while((**it)!="}" ) {
            (*it)++; index++;
        }
    }
    (*it)++; index++;

    return index;
}