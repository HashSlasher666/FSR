#include "parser.h"
#include <fstream>
#include <iostream>

Parser::Parser(const std::string& filename) : filename(filename) {}

void Parser::parseGraph(int& numVertices, int& numEdges, std::vector<Edge>& edges) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    file >> numVertices >> numEdges;

    for (int i = 0; i < numEdges; ++i) {
        Edge edge;
        file >> edge.u >> edge.v;
        edges.push_back(edge);
    }
}
