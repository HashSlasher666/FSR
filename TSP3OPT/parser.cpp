#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

Parser::Parser(const std::string& filename) : filename(filename) {}

std::vector<Point> Parser::parseData() {
    std::vector<Point> points;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return points;
    }
    
    int N;
    file >> N; // Чтение числа вершин
    for (int i = 0; i < N; ++i) {
        Point p;
        file >> p.x >> p.y;
        points.push_back(p);
    }
    
    return points;
}
