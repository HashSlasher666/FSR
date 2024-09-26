#include "graph.h"

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjList.resize(vertices);
}

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); 
}

int Graph::getVertices() const {
    return vertices;
}

const std::vector<std::vector<int>>& Graph::getAdjList() const {
    return adjList;
}
