/**
 * Flight Gear Project
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */

#ifndef PROJECT_BOUNDMAP_H
#define PROJECT_BOUNDMAP_H



#include <map>
#include <vector>

using namespace std;

//is a map for "throtle - > /controls/throtle (when /cont.. is in Dictionary path.
// .. , "y" - >x (when x is in symbol table)
class BoundMap {

    map<string, string> boundMap;
    static BoundMap *map_instance;
public:
    static inline BoundMap *instance() {
        if (map_instance == nullptr) {
            map_instance = new BoundMap();
        }
        return map_instance;
    }

    inline void setValue(string &key, double val) {
        boundMap[key] = val;
    }

    inline map<string, string >* getMap() {
        return &boundMap;
    }

    inline string getValue(const string &key) {
        return boundMap[key];
    }
};

#endif //PROJECT_BOUNDMAP_H
