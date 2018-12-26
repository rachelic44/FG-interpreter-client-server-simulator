//
// Created by shanyyael on 12/24/18.
//

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

static int sockId;


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
    if(d->count(path)>0) {
        send = ("set " + path + " " + (to_string(d->at(path))) + "\r\n").c_str();
    } else {
        __throw_logic_error("the path is not in the map");
    }
    const char *buffer=send.c_str();
    int num=sockId;


    cout<<"change " + send<<endl;
    int n=write(sockId, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}


double ConnectCommand::excecute() {
    if(BoolSingelton::instance()->getDataIsOpen()) {


        cout << "connected1" << endl;
        (*it)++;
        string ip = (**it);
        (*it)++;
        int portno = stoi(**it);
        (*it)++;


        const char *ipp = ip.c_str();

        int sockfd, n;
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


        sockId = sockfd;
        cout << "connected2" << endl;


        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }


    } else {
        std::this_thread::__sleep_for(std::chrono::seconds(0),std::chrono::milliseconds(100));
    }


    }




