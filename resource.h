#ifndef RESOURCE_H
#define RESOURCE_H


#include <mutex>
#include <unordered_map>
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
    const static std::unordered_map<Resource, std::string> names;
    ResourceName();
public:
    static std::string get_name(Resource resource);
    static Resource get_resource(char resourceChar);
};

#endif
