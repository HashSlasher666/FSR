#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

Graph parseGraphFromInput(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        exit(1);
    }

    int vertices, edges;
    file >> vertices >> edges;
    Graph graph(vertices);

    int u, v;
    for (int i = 0; i < edges; ++i) {
        file >> u >> v;
        graph.addEdge(u, v);
    }

    return graph;
}
