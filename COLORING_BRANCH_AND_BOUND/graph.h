#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    Graph(int vertices); 
    void addEdge(int u, int v); 
    int getVertices() const; 
    const std::vector<std::vector<int>>& getAdjList() const; 

private:
    int vertices; 
    std::vector<std::vector<int>> adjList; 
};

#endif
