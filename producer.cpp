#include "producer.h"
#include <chrono>
#include <iostream>
#include <string>

Producer::Producer(const std::string type, Inventory& inventory, 
        ProfitPointsCounter& counter): description(type), inventory(inventory), 
                                                            counter(counter) {
    start();
}

void Producer::run() {
    while (!inventory.is_done()) {
        if (!inventory.pop(description))
            continue;
        std::this_thread::sleep_for(std::chrono::milliseconds(TIEMPO_TRABAJO));
        counter.count(description.benefit_points());
    }
}
