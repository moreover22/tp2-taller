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
    bool _is_empty();
    void wait_producer(std::unique_lock<std::mutex>& lk);
public:
    Inventory();
    void push(Resource resource);
    bool pop(ProducerDescription& producer_description);
    bool is_done();
    void show();
    void close();
};

#endif
