#include <mutex>
#include <string>
#include <vector>
#include "inventory.h"
#include "resource.h"

Inventory::Inventory() {
    resources.insert({Resource::Trigo, 0});
    resources.insert({Resource::Madera, 0});
    resources.insert({Resource::Carbon, 0});
    resources.insert({Resource::Hierro, 0});
}

void Inventory::push(Resource resource) {
    if (resources.count(resource) == 0)
        resources.insert({resource, 0});
    ++resources[resource];
    cv.notify_all();
}

bool Inventory::pop(ProducerDescription& producer_description) {
    std::unique_lock<std::mutex> lk(mtx);
    while (is_empty() && !is_done()) 
        cv.wait(lk);

    if (!producer_description.check_requirements(resources))
        return false;
    producer_description.consume_resources(resources);
    return true;
}

bool Inventory::is_empty() {
    for (auto const& resource: resources) {
        if (resource.second > 0)
            return false;
    }
    return true;
}

bool Inventory::is_done() {
    return is_closed;
}

void Inventory::close() {
    is_closed = true;
    cv.notify_all();
}

void Inventory::show() const {
    printf("Recursos restantes:\n");
    for (auto const& resource: resources) {
        if (resource.first == Resource::Null) continue;
        std::string r_name = ResourceName::get_name(resource.first);
        printf("  - %s: %u\n", r_name.c_str(), (unsigned int) resource.second);
    }
}
