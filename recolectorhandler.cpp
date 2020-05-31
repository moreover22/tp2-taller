#include "recolectorhandler.h"

void RecolectorHandler::create_recolecotors(size_t n) {
    for (size_t i = 0; i < n; ++i) {
        recolectores.push_back(new Recolector(cola, inventory));
    }
}
void RecolectorHandler::join() {
    for (auto& recolector: recolectores)
        recolector->join(); 
}

RecolectorHandler::~RecolectorHandler() {
    for (auto& recolector: recolectores)
        delete recolector;
}

void RecolectorHandler::push_resource(Resource& resource) {
    cola.push(resource);
}

void RecolectorHandler::queue_done() {
    cola.done();
}
