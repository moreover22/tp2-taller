#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H

#include <cstdio>
#include <deque>
#include <condition_variable>
#include <mutex>
#include "resource.h"

class BlockingQueue {
private:
    std::deque<Resource> resources;
    std::mutex m;
    std::condition_variable cola_cv;
    bool queue_done;
public:
    BlockingQueue() : 
        queue_done(false) {};
    void push(Resource resource);
    Resource pop();
    bool is_done();
    bool is_empty();
    void done();
    void print_queue();
};

#endif
