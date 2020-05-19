#ifndef PRODUCERDESCRIPTION_H
#define PRODUCERDESCRIPTION_H

#include "resource.h"
#include <map>
#include <string>

class ProducerDescription {
private:
    std::map<Resource, size_t> requirements;
    size_t puntos_beneficio = 0;
public:
    explicit ProducerDescription(const std::string type);
    bool check_requirements(const std::map<Resource, size_t>& 
                                                                resources);
    void consume_resources(std::map<Resource, size_t>& resources);
    size_t benefit_points() const;
};

#endif
