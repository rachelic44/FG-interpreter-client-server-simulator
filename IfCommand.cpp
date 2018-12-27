/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

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
        while((**it)!="}" ) {
            (*it)++; index++;
        }
    }
    (*it)++; index++;

    return index;
}