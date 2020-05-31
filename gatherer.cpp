#include "gatherer.h"
#include "resource.h"
#include <chrono>

Gatherer::Gatherer(BlockingQueue& queue, Inventory& inventory)
    : queue(queue), inventory(inventory) {
    start();
}

void Gatherer::run() {
    while (!queue.is_ready()) {
        Resource resource = queue.pop();
        std::this_thread::sleep_for(std::chrono::milliseconds(TIEMPO_TRABAJO));
        inventory.push(resource);
    }
}
