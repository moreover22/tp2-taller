#include <string>
#include "mapparser.h"
#include "resource.h"

void MapParser::parse(GathererHandler& gatherers) {
    std::string line;
    while (!stream.eof()) {
        std::getline(stream, line);
        for (auto c: line) {
            Resource resource = ResourceName::get_resource(c);
            if (resource != Resource::Null)
                gatherers.push_resource(resource);
        }
    }
    gatherers.queue_done();
}
