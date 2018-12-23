//
// Created by user on 23/12/18.
//

#ifndef PROJECT_SYMBOLTABLEMAP_H
#define PROJECT_SYMBOLTABLEMAP_H


#include <map>
#include <vector>

using namespace std;

class SymbolTableMap {

    map<string, double> pathMap;
    vector<int> symbolVector;
    static SymbolTableMap *map_instance;
public:
    static inline SymbolTableMap *instance() {
        if (map_instance == nullptr) {
            map_instance = new SymbolTableMap();
        }
        return map_instance;
    }

    inline void setValue(string &key, double val) {
        if(pathMap.count((key))>0) {
            pathMap.at(key)=val;
        }
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
#endif //PROJECT_SYMBOLTABLEMAP_H
