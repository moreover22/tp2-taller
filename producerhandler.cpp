#include "producerhandler.h"

void ProducerHandler::create_producers(size_t n) {
    for (size_t i = 0; i < n; ++i) {
        producers.push_back(new Producer(inventory));
    }
}

void ProducerHandler::join() {
    for (auto& producer: producers) {
        producer->join();
    }
}

ProducerHandler::~ProducerHandler() {
    for (auto& producer: producers) {
        delete producer;
    }
}
