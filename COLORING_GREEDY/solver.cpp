#include "solver.h"
#include <algorithm>
#include <iostream>


Solver::Solver(int numVertices, const std::vector<Edge>& edges) 
    : numVertices(numVertices), colors(numVertices, -1) {
    adjList.resize(numVertices);

    for (const auto& edge : edges) {
        adjList[edge.u].push_back(edge.v);
        adjList[edge.v].push_back(edge.u);
    }
}


void Solver::solve() {
    std::vector<std::pair<int, int>> degrees(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        degrees[i] = {adjList[i].size(), i}; 
    }


    std::sort(degrees.rbegin(), degrees.rend());


    for (const auto& degree_vertex : degrees) {
        int vertex = degree_vertex.second;
        
        std::vector<bool> usedColors(numVertices, false);

        for (int neighbor : adjList[vertex]) {
            if (colors[neighbor] != -1) {
                usedColors[colors[neighbor]] = true;
            }
        }

        int color = 0;
        while (usedColors[color]) {
            ++color;
        }
        colors[vertex] = color;
    }
}

void Solver::printSolution() const {
    std::cout << "Vertex : Color" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << i << " : " << colors[i] << std::endl;
    }
}
