//
// Created by user on 23/12/18.
//

#ifndef PROJECT_OPENDATASERVERCOMMAND_H
#define PROJECT_OPENDATASERVERCOMMAND_H

#include "Command.h"
#include <map>
#include "vector"
#include "ExpressionFactory.h"
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>

using namespace std;


struct serverParams {
    map<string,double>* maap;
    int portPa;
    int hertzPa;
};


class OpenDataServerCommand : public Command {

private:

    map<string,double&>* bindMap;
    map<string,double >* varMap;
    vector<string>::iterator* it;


public:
    int port;
    int hz;
    OpenDataServerCommand( map<string,double >*,vector<string>::iterator* it, map<string,double&>*);
    virtual double excecute ();
   // void readFromServer( map<string,double>* dictionaryMap,int,int);
    //vector<string> makeItSplitted(string s);
   // void initializeMap( map<string,double>* dictionaryMap,string s);

};


#endif //PROJECT_OPENDATASERVERCOMMAND_H
