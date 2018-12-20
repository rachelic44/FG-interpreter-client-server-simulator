
#include "DataReaderServer.h"

static void* openServer(void* portNum, void*readPerSecond) {
    int sockfd, newsockfd, clilen;
    vector<char> buffer;
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; //////////////
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((uint16_t)((int)(size_t)portNum));

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
    * go in sleep mode and will wait for the incoming connection */

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating.
     * Read line by line from the port 10 times a second. */

    //TODO: READ FROM SOCKET LINE BY LINE 10 TIMES A SECOND AND STORE ALL READ VALUES IN HASHTABLE
    //infinate loop
    while (1) {
        n = (int) read(newsockfd, &buffer, 1000);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
    }

}




