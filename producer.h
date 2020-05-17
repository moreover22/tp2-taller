#ifndef PRODUCER_H
#define PRODUCER_H

#include <condition_variable>
#include <mutex>

#include "thread.h"
#include "inventory.h"
class Producer : public Thread {
private:
    Inventory& inventory;
    const int TIEMPO_TRABAJO = 60;
public:
    explicit Producer(Inventory& inventory);
    void run() override;
    void producir();
    ~Producer() {}
};

#endif
