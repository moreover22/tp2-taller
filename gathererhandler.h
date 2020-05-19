#ifndef GATHERERHANDLER_H
#define GATHERERHANDLER_H

#include <vector>
#include <string>
#include <unordered_map>

#include "blockingqueue.h"
#include "gatherer.h"
#include "inventory.h"
#include "resource.h"
#include "workerparser.h"

class GathererHandler {
private:
    Inventory& inventory;
    std::unordered_map<std::string, BlockingQueue*> queues;
    std::unordered_map<std::string, std::vector<Gatherer*>> gatherers;
    std::unordered_map<Resource, BlockingQueue*> queues_by_type;
public:
    explicit GathererHandler(Inventory& inventory);
    void create_gatherers(WorkerParser& parser);
    void join();
    void push_resource(Resource resource);
    void queue_done();
    ~GathererHandler();
};

#endif
