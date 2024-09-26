#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

struct Item {
    int value;
    int weight;
};

// Функция для чтения предметов из файла
std::vector<Item> parseItemsFromInput(const std::string& filename);

int parseMaxWeight(const std::string& filename);

#endif
