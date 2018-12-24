//
// Created by user on 23/12/18.
//

/*
#include "DataReaderServer.h"

using namespace std;


vector<string> makeItSplitted(char* buffer) {
    vector<string> vec;
    string temp;
    while (*buffer !='\n') {
        while (*buffer != ',' && *buffer != '\n') {
            temp += *buffer;
            ++buffer;
        }
        vec.emplace_back(temp);
        temp = "";
        if(*buffer != '\n')
            ++buffer;
    }
    return vec;
}

void initializeMap(map<string, double> *dictionaryMap, char* s) {

    vector<string> splitted = makeItSplitted(s);

    dictionaryMap->at("/instrumentation/airspeed-indicator/indicated-speed-kt")=stod(splitted[0]);
    dictionaryMap->at("/instrumentation/altimeter/indicated-altitude-ft")=stod(splitted[1]);
    dictionaryMap->at("/instrumentation/altimeter/pressure-alt-ft")=stod(splitted[2]);
    dictionaryMap->at("/instrumentation/attitude-indicator/indicated-pitch-deg")=stod(splitted[3]);
    dictionaryMap->at("/instrumentation/attitude-indicator/indicated-roll-deg")=stod(splitted[4]);
    dictionaryMap->at("/instrumentation/attitude-indicator/internal-pitch-deg")=stod(splitted[5]);
    dictionaryMap->at("/instrumentation/attitude-indicator/internal-roll-deg")=stod(splitted[6]);
    dictionaryMap->at("/instrumentation/encoder/indicated-altitude-ft")=stod(splitted[7]);
    dictionaryMap->at("/instrumentation/encoder/pressure-alt-ft")=stod(splitted[8]);
    dictionaryMap->at( "/instrumentation/gps/indicated-altitude-ft")=stod(splitted[9]);
    dictionaryMap->at( "/instrumentation/gps/indicated-ground-speed-kt")=stod(splitted[10]);
    dictionaryMap->at( "/instrumentation/gps/indicated-vertical-speed")=stod(splitted[11]);
    dictionaryMap->at( "/instrumentation/heading-indicator/indicated-heading-deg")=stod(splitted[12]);
    dictionaryMap->at( "/instrumentation/magnetic-compass/indicated-heading-deg")=stod(splitted[13]);
    dictionaryMap->at( "/instrumentation/slip-skid-ball/indicated-slip-skid")=stod(splitted[14]);
    dictionaryMap->at( "/instrumentation/turn-indicator/indicated-turn-rate")=stod(splitted[15]);
    dictionaryMap->at(  "/instrumentation/vertical-speed-indicator/indicated-speed-fpm")=stod(splitted[16]);
    dictionaryMap->at(  "/controls/flight/aileron")=stod(splitted[17]);
    dictionaryMap->at( "/controls/flight/elevator")=stod(splitted[18]);
    dictionaryMap->at( "/controls/flight/rudder")=stod(splitted[19]);
    dictionaryMap->at( "/controls/flight/flaps")=stod(splitted[20]);
    dictionaryMap->at( "/controls/engines/engine/throttle")=stod(splitted[21]);
    dictionaryMap->at("/engines/engine/rpm")=stod(splitted[22]);
}


void DataReaderServer::operator()(int port, int hertz,map<string, double>* mapp) {
    int setSocket;
    int newsockfd;
    int clilen;
    char buffer[2014];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

/* First call to socket() function */
 /*   setSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (setSocket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
 /*   bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
 /*   if (bind(setSocket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

 /*   listen(setSocket, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
  /*  newsockfd = accept(setSocket, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    cout << "server added" << endl;
    while (true) {
        /* If connection is established then start communicating */
    /*    bzero(buffer, 2014);
        n = read(newsockfd, buffer, 2013);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        cout << buffer << endl;
        initializeMap(mapp,buffer);
      //  updateData();
        sleep(1 / hertz);
    }
}

*/