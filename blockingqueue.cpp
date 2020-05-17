#include "blockingqueue.h"
#include "resource.h"
#include <mutex>

void BlockingQueue::push(Resource resource) {
    {
        std::lock_guard<std::mutex> lk(m);
        resources.push_back(resource);
    }
    cola_cv.notify_all();
}

Resource BlockingQueue::pop() {
    std::unique_lock<std::mutex> lk(m);
    cola_cv.wait(lk, [&] {
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
        std::lock_guard<std::mutex> lk(m);
        queue_done = true;
    }
    cola_cv.notify_all();
}

void BlockingQueue::print_queue() {
    printf("-----------------------------\n");
    for (auto& q: resources) {
        printf("%s\n", ResourceName::get_name(q).c_str());
    }
    printf("-----------------------------\n");
}
