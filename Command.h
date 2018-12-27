/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H


class Command{

public:
    virtual double excecute()=0;
    virtual ~Command() = default;

};
#endif //PROJECT_COMMAND_H
