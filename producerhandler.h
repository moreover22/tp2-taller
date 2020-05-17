#ifndef PRODUCERHANDLER_H
#define PRODUCERHANDLER_H

#include <vector>
#include <condition_variable>
#include "inventory.h"
#include "producer.h"

class ProducerHandler {
private:
    Inventory& inventory;
    std::vector<Producer*> producers;
    std::mutex m;
public:
    explicit ProducerHandler(Inventory& inventory): inventory(inventory) {}
    void create_producers(size_t n);
    void join();
    ~ProducerHandler();
};
#endif
