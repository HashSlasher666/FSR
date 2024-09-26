#include "parser.h"
#include <fstream>
#include <iostream>

std::vector<Item> parseItemsFromInput(const std::string& filename) {
    std::vector<Item> items;
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return items;
    }

    int n, maxWeight;
    inputFile >> n >> maxWeight; 

    for (int i = 0; i < n; ++i) {
        Item item;
        inputFile >> item.value >> item.weight;
        items.push_back(item);
    }

    inputFile.close();
    return items;
}

int parseMaxWeight(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return -1;
    }

    int n, maxWeight;
    inputFile >> n >> maxWeight;

    inputFile.close();
    return maxWeight;
}
