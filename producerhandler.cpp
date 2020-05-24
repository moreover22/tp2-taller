#include "producerhandler.h"
#include <string>
#include <vector>

void ProducerHandler::create_producers(WorkerParser& parser) {
    std::vector<std::string> producers_type { 
        "Cocineros",
        "Carpinteros",
        "Armeros" 
    };
    for (const auto producer_type : producers_type) {
        size_t cantidad = parser.get_quantity(producer_type);
        create_n_producers(producer_type, cantidad);
    }
}

// no usar copia, usar move
void ProducerHandler::create_n_producers(std::string type, size_t n) {
    for (size_t i = 0; i < n; ++i)
        producers.push_back(new Producer(type, inventory, counter));
}


void ProducerHandler::join() {
    for (auto& producer: producers)
        producer->join();
}

ProducerHandler::~ProducerHandler() {
    for (auto& producer: producers)
        delete producer;
}
