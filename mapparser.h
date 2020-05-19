#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <fstream>
#include "gathererhandler.h"

class MapParser {
private:
    std::ifstream& stream;
public:
    explicit MapParser(std::ifstream& stream) : stream(stream) {}
    void parse(GathererHandler& gatherers);
};
#endif
