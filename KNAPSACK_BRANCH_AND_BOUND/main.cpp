#include <iostream>
#include <vector>
#include "parser.h"
#include "solver.h"

int main() {
    std::string filename;
    std::cout << "Enter input file name: ";
    std::cin >> filename;

    int capacity;
    std::vector<Item> items = parseItemsFromFile(filename, capacity);

    if (items.empty()) {
        std::cerr << "Error reading items from file\n";
        return 1;
    }

    auto result = knapsackBranchAndBound(items, capacity);

    std::cout << "Maximum profit: " << result.first << std::endl;
    std::cout << "Items taken: ";
    for (bool taken : result.second) {
        std::cout << (taken ? 1 : 0) << " ";
    }
    std::cout << std::endl;

    std::cin.ignore();
    std::cin.get();
    return 0;
}
