#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

struct Item {
    int value;
    int weight;
};

class Parser {
public:
    Parser(const std::string& filename);
    std::vector<Item> parseItems();
    int getCapacity() const;

private:
    std::string filename;
    int capacity;
};

#endif
