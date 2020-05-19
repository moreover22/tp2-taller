#ifndef GATHERER_H
#define GATHERER_H

#include <condition_variable>
#include <mutex>

#include "thread.h"
#include "blockingqueue.h"
#include "inventory.h"

class Gatherer : public Thread {
private:
    BlockingQueue& queue;
    Inventory& inventory;
    const int TIEMPO_TRABAJO = 50;
public:
    Gatherer(BlockingQueue& queue, Inventory& inventory);
    void run() override;
};

#endif
