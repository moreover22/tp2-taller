#include "resource.h"
#include <mutex>

const std::unordered_map<Resource, std::string> ResourceName::names {
    { Resource::Carbon, "Carbón" },
    { Resource::Madera, "Madera" },
    { Resource::Hierro, "Hierro" },
    { Resource::Trigo, "Trigo" }
};

std::string ResourceName::get_name(Resource resource) {
    return ResourceName::names.at(resource);
}

Resource ResourceName::get_resource(char resourceChar) {
    for (auto& name: names) {
        if (name.second[0] == resourceChar){
            return name.first;
        }
    }
    return Resource::Null;
}


