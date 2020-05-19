#include <vector>
#include "gathererhandler.h"
#include "gatherer.h"
#include "workerparser.h"

GathererHandler::GathererHandler(Inventory& inventory) : inventory(inventory) {
    gatherers.insert({"Agricultores", std::vector<Gatherer*>()});
    gatherers.insert({"Leniadores", std::vector<Gatherer*>()});
    gatherers.insert({"Mineros", std::vector<Gatherer*>()});
    for (const auto& gatherer: gatherers) {
        queues.insert({gatherer.first, new BlockingQueue()});
    }
    queues_by_type = {
        { Resource::Trigo, queues.at("Agricultores") },
        { Resource::Madera, queues.at("Leniadores") },
        { Resource::Carbon, queues.at("Mineros") },
        { Resource::Hierro, queues.at("Mineros") },
    };
}

void GathererHandler::create_gatherers(WorkerParser& parser) {
    for (auto& gatherer: gatherers) {        
        size_t cantidad = parser.get_quantity(gatherer.first);
        BlockingQueue* queue = queues.at(gatherer.first);
        for (size_t i = 0; i < cantidad; ++i)
            gatherer.second.push_back(new Gatherer(*queue, inventory));
    }
}

void GathererHandler::join() {
    for (auto& gatherer_v: gatherers)
        for (auto& gatherer: gatherer_v.second)
            gatherer->join(); 
}

GathererHandler::~GathererHandler() {
    for (auto& queue: queues)
        delete queue.second;

    for (auto& gatherer_v: gatherers)
        for (auto& gatherer: gatherer_v.second)
            delete gatherer;
}

void GathererHandler::push_resource(Resource resource) {
    queues_by_type.at(resource)->push(resource);
}

void GathererHandler::queue_done() {
    for (auto& queue: queues) {
        queue.second->done();
    }
}
