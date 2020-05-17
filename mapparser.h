#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <fstream>
#include <map>
#include "recolectorhandler.h"
#include "resource.h"

class MapParser {
private:
    std::ifstream& stream;
public:
    explicit MapParser(std::ifstream& stream) : stream(stream) {}
    void parse(std::map<Resource, RecolectorHandler*>& queues);
};
#endif
