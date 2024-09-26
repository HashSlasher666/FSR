#include "solver.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <iomanip>

Solver::Solver(const std::vector<Point>& points) : points(points), bestDistance(std::numeric_limits<double>::max()) {
    bestTour.resize(points.size());
    for (int i = 0; i < points.size(); ++i) {
        bestTour[i] = i;
    }
}

double Solver::calculateDistance(const Point& a, const Point& b) const {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

double Solver::totalDistance(const std::vector<int>& tour) const {
    double dist = 0;
    for (size_t i = 0; i < tour.size() - 1; ++i) {
        dist += calculateDistance(points[tour[i]], points[tour[i + 1]]);
    }
    dist += calculateDistance(points[tour.back()], points[tour[0]]);
    return dist;
}

std::vector<int> Solver::swap_2opt(const std::vector<int>& route, int i, int k) {
    std::vector<int> new_route(route.begin(), route.begin() + i);
    new_route.insert(new_route.end(), route.rbegin() + (route.size() - k - 1), route.rbegin() + (route.size() - i));
    new_route.insert(new_route.end(), route.begin() + k + 1, route.end());
    return new_route;
}

void Solver::twoOpt() {
    bool improvement = true;
    while (improvement) {
        improvement = false;
        for (int i = 1; i < points.size() - 1; ++i) {
            for (int k = i + 1; k < points.size(); ++k) {
                std::vector<int> newTour = swap_2opt(bestTour, i, k);
                double newDistance = totalDistance(newTour);
                if (newDistance < bestDistance) {
                    bestTour = newTour;
                    bestDistance = newDistance;
                    improvement = true;
                }
            }
        }
    }
}

void Solver::solve() {
    bestDistance = totalDistance(bestTour); 
    twoOpt();  // запускаем 2-opt для оптимизации
}

void Solver::printSolution() const {
    std::cout << std::fixed << std::setprecision(1) << bestDistance << " 0" << std::endl;
    
    for (int i : bestTour) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
