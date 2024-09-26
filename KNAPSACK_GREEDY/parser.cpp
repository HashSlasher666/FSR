#include "parser.h"
#include <fstream>
#include <iostream>

Parser::Parser(const std::string& filename) : filename(filename), capacity(0) {}

std::vector<Item> Parser::parseItems() {
    std::vector<Item> items;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return items;
    }

    int numItems;
    file >> numItems >> capacity;

    for (int i = 0; i < numItems; ++i) {
        Item item;
        file >> item.value >> item.weight;
        items.push_back(item);
    }

    return items;
}

int Parser::getCapacity() const {
    return capacity;
}
