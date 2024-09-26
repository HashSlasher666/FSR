#include "solver.h"
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> edgeColoring(const Graph& graph) {
    int V = graph.getVertices();
    const auto& adjList = graph.getAdjList();

    int maxDegree = 0;
    for (const auto& neighbors : adjList) {
        maxDegree = std::max(maxDegree, (int)neighbors.size());
    }

    std::vector<int> edgeColors(V, -1); 

    for (int u = 0; u < V; ++u) {
        std::vector<bool> available(maxDegree, true); 

        for (int v : adjList[u]) {
            if (edgeColors[v] != -1) {
                available[edgeColors[v]] = false;
            }
        }

        int cr;
        for (cr = 0; cr < maxDegree; ++cr) {
            if (available[cr]) break;
        }

        edgeColors[u] = cr;
    }

    return edgeColors;
}
