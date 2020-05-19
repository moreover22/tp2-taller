#ifndef RESOURCE_H
#define RESOURCE_H

#include <map>
#include <string>

enum class Resource {
    Trigo, 
    Madera, 
    Carbon,
    Hierro,
    Null
};

class ResourceName {
private:
    const static std::map<Resource, std::string> names;
    ResourceName();
public:
    static std::string get_name(Resource resource);
    static Resource get_resource(char resourceChar);
};

#endif
