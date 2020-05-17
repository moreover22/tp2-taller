#include "inventory.h"

void Inventory::push(Resource resource) {
    std::lock_guard<std::mutex> lk(m);
    if (resources.count(resource) == 0)
        resources.insert({resource, 0});
    ++resources[resource];
}

Resource Inventory::pop() {
    return Resource::Madera;
}

void Inventory::show() const {
    printf("\n\n=================================\n");
    printf("[Inventrario]\n");
    for (auto const& resource: resources) {
        printf("--- %s: %u\n", ResourceName::get_name(resource.first).c_str(), 
                                                            resource.second);
    }
    printf("=================================\n\n");

}

