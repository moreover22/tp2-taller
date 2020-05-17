#include <map>
#include <string>
#include "mapparser.h"
#include "resource.h"


void MapParser::parse(std::map<Resource, RecolectorHandler*>& queues) {
    std::string line;
    do {
        std::getline(stream, line);
        for (auto c: line) {
            Resource resource = ResourceName::get_resource(c);
            queues[resource]->push_resource(resource);
        }
    } while (!line.empty());
}
