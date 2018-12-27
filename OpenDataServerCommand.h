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
#include "Command.h"
//#include "Reader.h"
#include <vector>
#include <string.h>
#include <sstream>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <pthread.h>
#include "DictionaryPath.h"
#include "BoolSingelton.h"


using namespace std;

struct serverParams {
    map<string,double>* maap=DictionaryPath::instance()->getMap();
    int portPa;
    int hertzPa;
    pthread_mutex_t * mutex;
    pthread_cond_t* cond;
    vector<string>::iterator* it;
    pthread_t *pthread;
};

class OpenDataServerCommand : public Command {
private:
    map<string,double&>* bindMap;
    map<string,double >* varMap;
    vector<string>::iterator* it;
    static bool shouldStop;
    ExpressionFactory* expressionFactory;

public:
    int port;
    int hz;
    OpenDataServerCommand( map<string,double >*,vector<string>::iterator* it, map<string,double&>*,
                           ExpressionFactory* expressionFactory);
    virtual double excecute ();

    // void readFromServer( map<string,double>* dictionaryMap,int,int);
    //vector<string> makeItSplitted(string s);
    // void initializeMap( map<string,double>* dictionaryMap,string s);
};
#endif //PROJECT_OPENDATASERVERCOMMAND_H
//