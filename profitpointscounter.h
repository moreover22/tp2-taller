#ifndef PROFITPOINTSCOUNTER_H
#define PROFITPOINTSCOUNTER_H

class ProfitPointsCounter {
private:
    int profit_points;
public:
    ProfitPointsCounter() : profit_points(0) {}
    void contar(int cantidad);
    void show() const;
};

#endif
