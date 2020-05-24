#include "resource.h"
#include <mutex>
#include <string>
#include <map>

const std::map<Resource, std::string> ResourceName::names {
    { Resource::Carbon, "Carbon" },
    { Resource::Madera, "Madera" },
    { Resource::Hierro, "Hierro" },
    { Resource::Trigo, "Trigo" },
    { Resource::Null, "NULL" },
};

// no usar copia, usar move
std::string ResourceName::get_name(Resource resource) { // Resource &resource, std::string&
    return ResourceName::names.at(resource);
}

Resource ResourceName::get_resource(char resourceChar) { // Resource&
    for (auto& name: names) {
        if (name.second[0] == resourceChar){
            return name.first;
        }
    }
    return Resource::Null;
}


