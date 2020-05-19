#ifndef PRODUCER_H
#define PRODUCER_H

#include <condition_variable>
#include <mutex>
#include <string>

#include "profitpointscounter.h"
#include "thread.h"
#include "inventory.h"
#include "producerdescription.h"

class Producer : public Thread {
private:
    ProducerDescription description;
    Inventory& inventory;
    ProfitPointsCounter& counter;
    const int TIEMPO_TRABAJO = 60;
public:
    Producer(const std::string type, Inventory& inventory, 
                                                ProfitPointsCounter& counter);
    void run() override;
};

#endif
