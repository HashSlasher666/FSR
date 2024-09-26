#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

struct Point {
    double x, y;
};

class Parser {
public:
    Parser(const std::string& filename);
    std::vector<Point> parseData();

private:
    std::string filename;
};

#endif
