#include "PrintCommand.h"
#include "ShuntingYard.h"
#include <ostream>
#include "CommandVar.h"
#include "CommandAssign.h"


using namespace std;
PrintCommand::PrintCommand(map<string, double> *varMap, vector<string>::iterator *it) {
    this->it = it;
    this->varMap = varMap;
}

double PrintCommand::excecute() {
    int index=0;
    Expression *e;
    string str="";
    (*it)++; index++;
    if ((*(*it))[0] == '"') {


        while (((*(*it))[((*(*it)).length())-1] != '"')) {
            str+=(**it)+" ";
            (*it)++; index++;
        }
        str+=(**it);
        (*it)++; index++;
        if((*(*it)=="\n")) {
            (*it)++; index++;
        }
        str.erase(0,1);
        str.erase(str.length()-1,1);
        cout << (str);
    } else {
        e = new ShuntingYard(this->varMap,(*(*it)));
        cout << e->evaluate();
        (*it)++; index++;
        if((*(*it)=="\n")) {
            (*it)++; index++;
        }
    }
    return index;

}