#ifndef SOLVER_H
#define SOLVER_H

#include "parser.h"
#include <vector>

class Solver {
public:
    Solver(int numVertices, const std::vector<Edge>& edges);
    void solve();
    void printSolution() const;

private:
    int numVertices;
    std::vector<std::vector<int>> adjList;
    std::vector<int> colors;
};

#endif
