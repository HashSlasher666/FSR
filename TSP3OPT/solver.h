#ifndef SOLVER_H
#define SOLVER_H

#include "parser.h"
#include <vector>

class Solver {
public:
    Solver(const std::vector<Point>& points);
    void solve();
    void printSolution() const;

private:
    double calculateDistance(const Point& a, const Point& b) const;
    double totalDistance(const std::vector<int>& tour) const;
    std::vector<int> swap_3opt(const std::vector<int>& route, int i, int j, int k);
    void threeOpt();

    std::vector<Point> points;
    std::vector<int> bestTour;
    double bestDistance;
};

#endif
