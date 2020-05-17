#include "producer.h"
#include <chrono>
#include <iostream>

Producer::Producer(Inventory& inventory) 
    : inventory(inventory) {
    start();
}

void Producer::run() {
   std::this_thread::sleep_for(std::chrono::milliseconds(TIEMPO_TRABAJO));
}

void Producer::producir() {
}