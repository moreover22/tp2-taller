#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <fstream>
#include <unordered_map>
#include "recolectorhandler.h"
#include "resource.h"

class MapParser {
private:
    std::ifstream& stream;
public:
    MapParser(std::ifstream& stream) : stream(stream) {}
    void parse(std::unordered_map<Resource, RecolectorHandler*>& queues);
};
#endif
