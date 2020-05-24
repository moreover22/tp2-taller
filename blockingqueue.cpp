#include "blockingqueue.h"
#include "resource.h"
#include <mutex>

void BlockingQueue::push(Resource resource) {
    {
        std::lock_guard<std::mutex> lk(mtx);
        resources.push_back(resource);
    }
    queue_cv.notify_all();
}

Resource BlockingQueue::pop() {
    std::unique_lock<std::mutex> lk(mtx);
    queue_cv.wait(lk, [&] {
        return !this->is_empty() || this->is_done();
    });
    if (is_empty())
        return Resource::Null;
    Resource frente = resources.front();
    resources.pop_front();
    return frente;
}

bool BlockingQueue::is_done() {
    // no es una funcion atomica
    
    return queue_done;
}

bool BlockingQueue::is_empty() {
    // no es una funcion atomica
    return resources.empty();
}

void BlockingQueue::done() {
    {
        std::lock_guard<std::mutex> lk(mtx);
        queue_done = true;
    }
    queue_cv.notify_all();
}
