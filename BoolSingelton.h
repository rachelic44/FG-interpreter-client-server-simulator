/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#ifndef PROJECT_BOOLSINGELTON_H
#define PROJECT_BOOLSINGELTON_H


#include <map>
#include <vector>

using namespace std;

class BoolSingelton {

    bool dataIsOpen=false;
    bool stopTheThread=false;
    int socket;
    static BoolSingelton *boolInstance;
public:
    static inline BoolSingelton *instance() {
        if (boolInstance == nullptr) {
            boolInstance = new BoolSingelton();

        }
        return boolInstance;
    }

    inline void setValue(bool b) {
        dataIsOpen=b;
    }

    inline bool getDataIsOpen() {
        return dataIsOpen;
    }

    inline void setValueOfThreadCloase(bool b) {
        stopTheThread=b;
    }

    inline bool getDataIsOpenOfThreadCloase() {
        return stopTheThread;
    }

    inline int getSocketOfOpenedServer() {
        return socket;
    }
    inline void setSocketOfOpenedServer(int s) {
        socket=s;
    }


};




#endif //PROJECT_BOOLSINGELTON_H
