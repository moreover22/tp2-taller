#ifndef INVENTORY_H
#define INVENTORY_H
#include <condition_variable>
#include <mutex>
#include <map>
#include "producerdescription.h"
#include "resource.h"

class Inventory {
private:
    std::map<Resource, size_t> resources;
    std::mutex mtx;
    std::condition_variable cv;
    bool is_closed = false;
public:
    Inventory();
    void push(Resource resource);
    bool pop(ProducerDescription& producer_description);
    void show() const;
    bool is_empty();
    bool is_done();
    void close();
};

#endif
