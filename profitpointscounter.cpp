#include "profitpointscounter.h"
#include <mutex>

void ProfitPointsCounter::count(int cantidad) {
    std::lock_guard<std::mutex> lk(mtx);
    profit_points += cantidad;
}

void ProfitPointsCounter::show() const {
    printf("Puntos de Beneficio acumulados: %u", (unsigned int) profit_points);
    printf("\n");
}
