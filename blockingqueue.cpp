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
        return !resources.empty() || queue_done;
    });
    if (resources.empty())
        return Resource::Null;
    Resource frente = resources.front();
    resources.pop_front();
    return frente;
}

bool BlockingQueue::is_ready() {
    std::unique_lock<std::mutex> lk(mtx);
    return resources.empty() && queue_done;
}

void BlockingQueue::done() {
    {
        std::lock_guard<std::mutex> lk(mtx);
        queue_done = true;
    }
    queue_cv.notify_all();
}
