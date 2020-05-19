#ifndef PROFITPOINTSCOUNTER_H
#define PROFITPOINTSCOUNTER_H

#include <mutex>

class ProfitPointsCounter {
private:
    std::size_t profit_points;
    std::mutex mtx;
public:
    ProfitPointsCounter(): profit_points(0) {}
    void count(int cantidad);
    void show() const;
};

#endif
