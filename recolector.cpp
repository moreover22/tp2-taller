#include "recolector.h"
#include "resource.h"
#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>
#include <utility>

Recolector::Recolector(BlockingQueue& cola, Inventory& inventory) : cola(cola), 
                                                        inventory(inventory) {
    start();
}

void Recolector::run() {
    while (!cola.is_ready()) {
        Resource resource = std::move(cola.pop());
        std::this_thread::sleep_for(std::chrono::milliseconds(TIEMPO_TRABAJO));
        inventory.push(resource);
    }
}
