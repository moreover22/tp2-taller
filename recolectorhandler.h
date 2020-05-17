#ifndef RECOLECTORHANDLER_H
#define RECOLECTORHANDLER_H

#include <vector>
#include <string>
#include "blockingqueue.h"
#include "recolector.h"
#include "inventory.h"
#include "resource.h"

class RecolectorHandler {
private:
    BlockingQueue cola;
    
    Inventory& inventory;
    std::vector<Recolector*> recolectores;
public:
    explicit RecolectorHandler(Inventory& inventory) 
        : cola(), inventory(inventory) {}
    void create_recolecotors(size_t n);
    void join();

    void push_resource(Resource resource);
    void queue_done();

    ~RecolectorHandler();
};

#endif
