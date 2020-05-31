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
const Resource null_resource = Resource::Null;

std::string ResourceName::get_name(const Resource& resource) {
    return ResourceName::names.at(resource);
}

const Resource& ResourceName::get_resource(char resourceChar) {
    for (auto& name: names) {
        if (name.second[0] == resourceChar){
            return name.first;
        }
    }
    return null_resource;
}
