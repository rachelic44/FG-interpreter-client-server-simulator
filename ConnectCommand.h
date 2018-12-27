/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H


#include <string>
#include "Command.h"
#include "ExpressionFactory.h"
#include <map>
#include <vector>
#include "BoolSingelton.h"

using namespace std;
///VHJG
class ConnectCommand : public Command {
private:
    map<string,double&>* bindMap;
    map<string,double >* varMap;
    vector<string>::iterator* it;
    static bool shouldStop;
    ExpressionFactory* expressionFactory;
public:
    static void writeFunc(string path);
    ConnectCommand(map<string,double >* varMap,vector<string>::iterator* it,map<string,double&>* bindMap
            ,ExpressionFactory* expressionFactory);
    double excecute();
};


#endif //PROJECT_CONNECTCOMMAND_H
