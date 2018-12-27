/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#include "ConnectCommand.h"
#include "DictionaryPath.h"

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <string.h>
#include <thread>

using namespace std;



ConnectCommand::ConnectCommand(map<string, double> *varMp, vector<string>::iterator *itt,
                                             map<string, double &> *bindMapp, ExpressionFactory *expressionFactory) {
    this->expressionFactory = expressionFactory;
    this->bindMap = bindMapp;
    this->it = itt;
    this->varMap = varMp;
}

void ConnectCommand::writeFunc(string path) {
    map<string,double>* d=DictionaryPath::instance()->getMap();
    string send;
    string copyPath=path;
    copyPath.erase(0,1);
    if(d->count(path)>0) {
        send = ("set " + copyPath + " " + (to_string(d->at(path))) + "\r\n").c_str();
    } else {
        __throw_logic_error("the path is not in the map");
    }
    const char *buffer=send.c_str();
    int sockID=BoolSingelton::instance()->getSocketOfOpenedServer();
    int n=write(sockID, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}


double ConnectCommand::excecute() {
    if(BoolSingelton::instance()->getDataIsOpen()) {
        (*it)++;
        string ip = (**it);
        (*it)++;
        int portno = stoi(**it);
        (*it)++;

        const char *ipp = ip.c_str();

        int sockfd;
        struct sockaddr_in serv_addr;
        struct hostent *server;

        /* Create a socket point */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }
        server = gethostbyname(ipp);
        if (server == NULL) {
            fprintf(stderr, "ERROR, no such host\n");
            exit(0);
        }
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(portno);
        /* Now connect to the server */
        if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR connecting");
            exit(1);
        }
        BoolSingelton::instance()->setSocketOfOpenedServer(sockfd);
    } else {
        std::this_thread::__sleep_for(std::chrono::seconds(0),std::chrono::milliseconds(100));
    }


    return 0;
    }
