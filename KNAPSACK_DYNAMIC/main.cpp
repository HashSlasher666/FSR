#include "parser.h"
#include "solver.h"
#include <iostream>
#include <vector>

int main() {
    std::string filename;
    std::cout << "Enter the input file name: ";
    std::cin >> filename;

    std::vector<Item> items = parseItemsFromInput(filename);
    int maxWeight = parseMaxWeight(filename);

    if (items.empty() || maxWeight < 0) {
        std::cerr << "Error in input data." << std::endl;
        return 1;
    }

    auto result = solveKnapsackDynamic(items, maxWeight);

    std::cout << "Maximum value: " << result.first << std::endl;

    std::cout << "Selected items: ";
    for (int i : result.second) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.get();
    std::cin.get();

    return 0;
}
