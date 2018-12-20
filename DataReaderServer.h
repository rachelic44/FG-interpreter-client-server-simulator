//
// Created by shanyyael on 12/19/18.
//

#ifndef PROJECT_DATAREADERSERVER_H
#define PROJECT_DATAREADERSERVER_H


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <vector>

using namespace std;

static void* openServer(void* portNum);

class DataReaderServer {
public:

};


#endif //PROJECT_DATAREADERSERVER_H
