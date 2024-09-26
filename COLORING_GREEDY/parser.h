#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

struct Edge {
    int u, v;  
};

class Parser {
public:
    Parser(const std::string& filename);
    void parseGraph(int& numVertices, int& numEdges, std::vector<Edge>& edges);

private:
    std::string filename;
};

#endif
