#include "solver.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <algorithm>  // Для std::reverse
#include <iomanip>    // Для setprecision

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

std::vector<int> Solver::swap_3opt(const std::vector<int>& route, int i, int j, int k) {
    std::vector<std::vector<int>> newRoutes;

 
    std::vector<int> route1(route.begin(), route.begin() + i);  
    std::vector<int> part1(route.begin() + i, route.begin() + j); 
    std::vector<int> part2(route.begin() + j, route.begin() + k); 
    std::vector<int> route2(route.begin() + k, route.end()); 

    std::reverse(part1.begin(), part1.end());
    std::reverse(part2.begin(), part2.end()); 
    
    route1.insert(route1.end(), part1.begin(), part1.end());
    route1.insert(route1.end(), part2.begin(), part2.end());
    route1.insert(route1.end(), route2.begin(), route2.end());

    newRoutes.push_back(route1);

    return newRoutes[0];
}

void Solver::threeOpt() {
    bool improvement = true;
    while (improvement) {
        improvement = false;
        for (int i = 1; i < points.size() - 2; ++i) {
            for (int j = i + 1; j < points.size() - 1; ++j) {
                for (int k = j + 1; k < points.size(); ++k) {
                    std::vector<int> newTour = swap_3opt(bestTour, i, j, k);
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
}

void Solver::solve() {
    bestDistance = totalDistance(bestTour); 
    threeOpt();
}

void Solver::printSolution() const {
    std::cout << std::fixed << std::setprecision(1) << bestDistance << " 0" << std::endl;
    
    for (int i : bestTour) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
