#include <string>
#include "mapparser.h"
#include "resource.h"


void MapParser::parse(GathererHandler& gatherers) {
    std::string line;
    do {
        std::getline(stream, line);
        for (auto c: line) {
            Resource resource = ResourceName::get_resource(c);
            if (resource == Resource::Null) continue;
            gatherers.push_resource(resource);
        }
    } while (!line.empty());
    gatherers.queue_done();
}
