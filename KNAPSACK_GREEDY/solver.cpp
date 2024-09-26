#include "solver.h"
#include <algorithm>
#include <iostream>

Solver::Solver(const std::vector<Item>& items, int capacity) : items(items), capacity(capacity), totalValue(0) {}

bool compareItems(const Item& a, const Item& b) {
    double ratioA = static_cast<double>(a.value) / a.weight;
    double ratioB = static_cast<double>(b.value) / b.weight;
    return ratioA > ratioB;
}

void Solver::solve() {
    selectedItems.assign(items.size(), 0);

    std::sort(items.begin(), items.end(), compareItems);

    int currentWeight = 0;
    
    for (size_t i = 0; i < items.size(); ++i) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            selectedItems[i] = 1;
        }
    }
}

void Solver::printSolution() const {
    std::cout << totalValue << std::endl;
    for (int i : selectedItems) {
        std::cout << i << " "; 
    }
    std::cout << std::endl;
}
