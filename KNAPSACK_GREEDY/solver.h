#ifndef SOLVER_H
#define SOLVER_H

#include "parser.h"
#include <vector>

class Solver {
public:
    Solver(const std::vector<Item>& items, int capacity);
    void solve();
    void printSolution() const;

private:
    std::vector<Item> items;
    int capacity;
    std::vector<int> selectedItems;
    int totalValue;
};

#endif
