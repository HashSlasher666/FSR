#include "parser.h"
#include <fstream>
#include <iostream>

std::vector<Item> parseItemsFromFile(const std::string& filename, int& capacity) {
    std::vector<Item> items;
    std::ifstream inputFile(filename);
    
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file\n";
        return items;
    }
    
    int n;
    inputFile >> n >> capacity;
    
    for (int i = 0; i < n; ++i) {
        Item item;
        inputFile >> item.value >> item.weight;
        items.push_back(item);
    }
    
    inputFile.close();
    return items;
}
