#ifndef RECOLECTOR_H
#define RECOLECTOR_H

#include <condition_variable>
#include <mutex>

#include "thread.h"
#include "blockingqueue.h"
#include "inventory.h"

class Recolector : public Thread {
private:
    BlockingQueue& cola;
    Inventory& inventory;
    const int TIEMPO_TRABAJO = 50;
public:
    Recolector(BlockingQueue& cola, Inventory& inventory);
    void run() override;
    ~Recolector() {}
};

#endif
