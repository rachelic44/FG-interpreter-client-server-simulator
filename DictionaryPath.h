/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#ifndef PROJECT_DICTIONARYPATH_H
#define PROJECT_DICTIONARYPATH_H


#include <map>
#include <vector>

using namespace std;

class DictionaryPath {

    map<string, double> pathMap;
    static DictionaryPath *map_instance;
public:
    static inline DictionaryPath *instance() {
        if (map_instance == nullptr) {
            map_instance = new DictionaryPath();
            vector<string> pathVector{"/instrumentation/airspeed-indicator/indicated-speed-kt",
                                      "/instrumentation/altimeter/indicated-altitude-ft",
                                      "/instrumentation/altimeter/pressure-alt-ft",
                                      "/instrumentation/attitude-indicator/indicated-pitch-deg",
                                      "/instrumentation/attitude-indicator/indicated-roll-deg",
                                      "/instrumentation/attitude-indicator/internal-pitch-deg",
                                      "/instrumentation/attitude-indicator/internal-roll-deg",
                                      "/instrumentation/encoder/indicated-altitude-ft",
                                      "/instrumentation/encoder/pressure-alt-ft",
                                      "/instrumentation/gps/indicated-altitude-ft",
                                      "/instrumentation/gps/indicated-ground-speed-kt",
                                      "/instrumentation/gps/indicated-vertical-speed",
                                      "/instrumentation/heading-indicator/indicated-heading-deg",
                                      "/instrumentation/magnetic-compass/indicated-heading-deg",
                                      "/instrumentation/slip-skid-ball/indicated-slip-skid",
                                      "/instrumentation/turn-indicator/indicated-turn-rate",
                                      "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                                      "/controls/flight/aileron",
                                      "/controls/flight/elevator",
                                      "/controls/flight/rudder",
                                      "/controls/flight/flaps",
                                      "/controls/engines/current-engine/throttle",
                                      "/engines/engine/rpm"};
            for(unsigned int i=0;i<pathVector.size();i++) {
                map_instance->setValue(pathVector[i],0);
            }
        }
        return map_instance;
    }

    inline void setValue(string &key, double val) {
        pathMap[key] = val;
    }

    inline map<string, double>* getMap() {
        return &pathMap;
    }

    inline double getValue(const string &key) {
        return pathMap[key];
    }
};

/*void DataReaderServer::initializeDictionaryMap(vector<string> vector) {
    for (int i = 0; i < FLIGHT_PARAMETERS; i++) {
        mtx.lock();
        dictionaryPath::instance()->setValue(pathVector[i], stoi(vector[i]));
        mtx.unlock();
    }
}

*/
#endif //PROJECT_DICTIONARYPATH_H
