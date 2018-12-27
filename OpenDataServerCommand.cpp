/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#include <iostream>
#include "OpenDataServerCommand.h"
#include "DictionaryPath.h"
#include <map>
#include <algorithm>

OpenDataServerCommand::OpenDataServerCommand(map<string, double> *varMp, vector<string>::iterator *itt,
                                             map<string, double &> *bindMapp, ExpressionFactory *expressionFactory) {
    this->expressionFactory = expressionFactory;
    this->bindMap = bindMapp;
    this->it = itt;
    this->varMap = varMp;
}

vector<string> makeItSplitted(const char *buffer) {
    vector<string> vec;
    string temp;
    while (*buffer != '\n') {
        while (*buffer != ',' && *buffer != '\n') {
            temp += *buffer;
            ++buffer;
        }
        vec.emplace_back(temp);
        temp = "";
        if (*buffer != '\n')
            ++buffer;
    }

    return vec;
}


void updateMaps(std::string str, map<string,double>* dictionaryMap) {

    double values[23]; /* Array for the values. */
    std::stringstream parser; /* Parse out string by commas */
    int counter = 0; /* Tells us which index to set. */

    /* Divide by commas and update the double array */
    parser.str(str);
    while (parser.good() && counter < 23) {
        std::string val;
        std::getline(parser, val, ',');
        values[counter] = std::strtod(val.c_str(), nullptr);
        ++counter;
    }
    parser.clear();

    /* Update the map */
    dictionaryMap->at("/instrumentation/airspeed-indicator/indicated-speed-kt")=values[0];
    dictionaryMap->at("/instrumentation/altimeter/indicated-altitude-ft")=values[1];
    dictionaryMap->at("/instrumentation/altimeter/pressure-alt-ft")=values[2];
    dictionaryMap->at("/instrumentation/attitude-indicator/indicated-pitch-deg")=values[3];
    dictionaryMap->at("/instrumentation/attitude-indicator/indicated-roll-deg")=values[4];
    dictionaryMap->at("/instrumentation/attitude-indicator/internal-pitch-deg")=values[5];
    dictionaryMap->at("/instrumentation/attitude-indicator/internal-roll-deg")=values[6];
    dictionaryMap->at("/instrumentation/encoder/indicated-altitude-ft")=values[7];
    dictionaryMap->at("/instrumentation/encoder/pressure-alt-ft")=values[8];
    dictionaryMap->at("/instrumentation/gps/indicated-altitude-ft")=values[9];
    dictionaryMap->at("/instrumentation/gps/indicated-ground-speed-kt")=values[10];
    dictionaryMap->at("/instrumentation/gps/indicated-vertical-speed")=values[11];
    dictionaryMap->at("/instrumentation/heading-indicator/indicated-heading-deg")=values[12];
    dictionaryMap->at("/instrumentation/magnetic-compass/indicated-heading-deg")=values[13];
    dictionaryMap->at("/instrumentation/slip-skid-ball/indicated-slip-skid")=values[14];
    dictionaryMap->at("/instrumentation/turn-indicator/indicated-turn-rate")=values[15];
    dictionaryMap->at("/instrumentation/vertical-speed-indicator/indicated-speed-fpm")=values[16];
    dictionaryMap->at("/controls/flight/aileron")=values[17];
    dictionaryMap->at("/controls/flight/elevator")=values[18];
    dictionaryMap->at("/controls/flight/rudder")=values[19];
    dictionaryMap->at("/controls/flight/flaps")=values[20];
    dictionaryMap->at("/controls/engines/current-engine/throttle")=values[21];
    dictionaryMap->at("/engines/engine/rpm")=values[22];
}
/**
 * Check's if the char* has a \n char.
 * @param data The char* to search in.
 * @return True if contains, else false.
 */
bool isNewLine(std::string& data) {

    return ((data.find('\n') != std::string::npos));
}


void readFromServer(map<string, double> *dictionaryMap, int portNU, int hz, pthread_mutex_t *mutex1,
                    pthread_cond_t *cond,vector<string>::iterator* it,pthread_t* pthread) {
    //pthread_mutex_lock(&mutex);


    std::string tillNewLine ; /* The set of  data. */
    std::string dataRead    ; /* The un-used data. */
    char buffer[1024];        /* The data we currently read. */
    int readBytes;            /* The bytes we currently read. */
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr{}, cli_addr{};
    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = portNU;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }


    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }


    // Endless loop, read data until program finishes.
    BoolSingelton* ins=BoolSingelton::instance();
    bool tostopTheThread=ins->getDataIsOpenOfThreadCloase();
    while (!tostopTheThread) {

        /* Read socket. */
        bzero(buffer, 1024);
        readBytes = (int) read(newsockfd, buffer, 1023);

        if (readBytes < 0) { /* Check if the read succeeded. */
            throw "Could not read from client."; /* If failed throw. */
        } else {
            BoolSingelton::instance()->setValue(true);

            /* Save our read data in a string. */
            dataRead += buffer;

            /* Check if this is a full set of data. */
            if (isNewLine(dataRead)) {

                /* Get the set of data. */
                tillNewLine = dataRead.substr(0, dataRead.find_first_of('\n'));

                /* Saving unused data in string. */
                dataRead = dataRead.substr(dataRead.find_first_of('\n') + 1, dataRead.size() - 1);

                /* Making sure there are no "leftovers" from data. */
                while (dataRead[0] == '\n') {
                    dataRead = dataRead.substr(1, dataRead.size() - 1);
                }

                /* Update map If we got new data. */
                if (!tillNewLine.empty()) {
                    pthread_mutex_lock(mutex1);
                    updateMaps(tillNewLine, dictionaryMap);
                    pthread_mutex_unlock(mutex1);
                }

                tillNewLine = "";
                dataRead.clear();
            }
        }
        sleep(hz/1000);
        tostopTheThread=ins->getDataIsOpenOfThreadCloase();
    }

    /* Close socket. */
    close(newsockfd);
    close(ins->getSocketOfOpenedServer());
    delete(mutex1);
   // close(*pthread);
}



void *threadOpen(void *params) {
    struct serverParams *parameters = static_cast<struct serverParams *>(params);
    map<string, double> *map = parameters->maap;
    int port = parameters->portPa;
    int hz = parameters->hertzPa;

    readFromServer(map, port, hz, parameters->mutex, parameters->cond,parameters->it,parameters->pthread);
    return 0;

}


double OpenDataServerCommand::excecute() {

    //skip the word "openDate"
    (*it)++;
    int port1 = expressionFactory->create((**it))->evaluate();
    int hertz = expressionFactory->create((**it))->evaluate();
    struct serverParams *params = new serverParams();
    params->maap = (DictionaryPath::instance()->getMap());
    params->portPa = port1;
    params->hertzPa = hertz;
    params->mutex = this->expressionFactory->getMutix();
    params->cond = this->expressionFactory->getCond();
    params->it=this->it;



    pthread_t pthread;
    params->pthread=&pthread;
    if (pthread_create(&pthread, nullptr, threadOpen, (void *) (params)) != 0) {
        perror("A problem accured");
    }
    // pthread_mutex_unlock(&mutex);
    return 0;
}
