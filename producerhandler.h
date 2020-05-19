#ifndef PRODUCERHANDLER_H
#define PRODUCERHANDLER_H

#include <vector>
#include <condition_variable>
#include <string>

#include "inventory.h"
#include "producer.h"
#include "profitpointscounter.h"
#include "workerparser.h"

class ProducerHandler {
private:
    Inventory& inventory;
    ProfitPointsCounter& counter;
    std::vector<Producer*> producers;
    void create_n_producers(std::string type, size_t n);
public:
    ProducerHandler(Inventory& inventory, ProfitPointsCounter& counter) 
        : inventory(inventory), counter(counter) {}
    void create_producers(WorkerParser& parser);
    void join();
    ~ProducerHandler();
};

#endif
