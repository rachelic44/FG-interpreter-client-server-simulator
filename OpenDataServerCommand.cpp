
//
#include <iostream>
#include "OpenDataServerCommand.h"
#include "DictionaryPath.h"
#include <map>
#include <algorithm>


pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

OpenDataServerCommand::OpenDataServerCommand(map<string, double> *varMp, vector<string>::iterator *itt,
                                             map<string, double &> *bindMapp,  ExpressionFactory* expressionFactory) {
    this->expressionFactory=expressionFactory;
    this->bindMap=bindMapp;
    this->it=itt;
    this->varMap=varMp;
}
vector<string> makeItSplitted(char * buffer) {
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
void initializeMap(map<string, double> *dictionaryMap, char* buffer) {
    vector<string> splitted = makeItSplitted(buffer);
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


void readFromServer( map<string,double>* dictionaryMap,int portNU, int hz,pthread_mutex_t* mutex1,
        pthread_cond_t* cond) {
    //pthread_mutex_lock(&mutex);

    int sockfd, newsockfd, portno, clilen;
    char buffer[2014];
    struct sockaddr_in serv_addr{}, cli_addr{};
    int  n;
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



    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    while(true) {


        bzero(buffer,2014);
        n = read( newsockfd,buffer,2013 );
        pthread_mutex_lock(mutex1);
        initializeMap(dictionaryMap,buffer);
        cout<<"success";
        pthread_mutex_unlock(mutex1);


        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        pthread_cond_signal(cond);
    }

   // pthread_cond_signal(&cond);
    //pthread_mutex_unlock(&mutex);
}


void* threadOpen(void * params) {
    struct serverParams* parameters= static_cast<struct serverParams*>(params);
    map<string,double >* map=parameters->maap;
    int port=parameters->portPa;
    int hz=parameters->hertzPa;


    readFromServer(map,port,hz,parameters->mutex,parameters->cond);

}


double OpenDataServerCommand::excecute() {

    //skip the word "openDate"
    (*it)++;
    int port1=expressionFactory->create((**it))->evaluate();
    int hertz=expressionFactory->create((**it))->evaluate();
    struct serverParams* params = new serverParams();
    params->maap=(DictionaryPath::instance()->getMap());
    params->portPa=port1;
    params->hertzPa=hertz;
    params->mutex=this->expressionFactory->getMutix();
    params->cond=this->expressionFactory->getCond();

    pthread_t pthread;
    
    //pthread_mutex_lock(&mutex);
    if(pthread_create(&pthread, nullptr,threadOpen,(void*)(params))!=0) {
        perror("A problem accured");
    }
   // pthread_mutex_unlock(&mutex);
}
