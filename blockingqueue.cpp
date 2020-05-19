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
    Resource frente = resources.front();
    resources.pop_front();
    return frente;
}

bool BlockingQueue::is_done() {
    return queue_done;
}

bool BlockingQueue::is_empty() {
    return resources.empty();
}

void BlockingQueue::done() {
    {
        std::lock_guard<std::mutex> lk(mtx);
        queue_done = true;
    }
    queue_cv.notify_all();
}
