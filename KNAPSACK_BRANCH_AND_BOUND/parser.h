#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

struct Item {
    int weight;
    int value;
};

std::vector<Item> parseItemsFromFile(const std::string& filename, int& capacity);

#endif
