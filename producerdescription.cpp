#include <string>
#include <map>
#include "producerdescription.h"

ProducerDescription::ProducerDescription(const std::string type) {
    if (type == "Cocineros") {
        requirements = {
            {Resource::Trigo, 2},
            {Resource::Carbon, 1}
        };
        puntos_beneficio = 5;
    } else if (type == "Carpinteros") {
        requirements = {
            {Resource::Madera, 3},
            {Resource::Hierro, 1}
        };
        puntos_beneficio = 2;
    } else if (type == "Armeros") {
        requirements = {
            {Resource::Hierro, 2},
            {Resource::Carbon, 2}
        };
        puntos_beneficio = 3;
    }
}

bool ProducerDescription::
    check_requirements(const std::map<Resource, size_t>& resources) {
    for (auto const& requirement: requirements) {
        Resource resource = requirement.first;
        if (resources.count(resource) == 0)
            return false;
        if (requirement.second > resources.at(resource))
            return false;
    }
    return true;
}

void ProducerDescription::
    consume_resources(std::map<Resource, size_t>& resources) {
    for (auto const& requirement: requirements) {
        Resource resource = requirement.first;
        resources[resource] -= requirement.second;
    }
}

size_t ProducerDescription::benefit_points() const {
    return puntos_beneficio;
}
