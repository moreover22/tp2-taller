#ifndef INVENTORY_H
#define INVENTORY_H
#include <mutex>
#include <unordered_map>
#include "resource.h"

class Inventory {
private:
    std::unordered_map<Resource, unsigned int> resources;
    std::mutex m;
public:
    void push(Resource resource);
    Resource pop();
    void show() const;
};

#endif
