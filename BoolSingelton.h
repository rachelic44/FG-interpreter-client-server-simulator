//
// Created by shanyyael on 12/25/18.
//

#ifndef PROJECT_BOOLSINGELTON_H
#define PROJECT_BOOLSINGELTON_H


#include <map>
#include <vector>

using namespace std;

class BoolSingelton {

    bool dataIsOpen=false;
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


};




#endif //PROJECT_BOOLSINGELTON_H
