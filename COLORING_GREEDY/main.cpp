#include "parser.h"
#include "solver.h"
#include <iostream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    Parser parser(filename);
    int numVertices, numEdges;
    std::vector<Edge> edges;
    parser.parseGraph(numVertices, numEdges, edges);

    if (edges.empty()) {
        std::cerr << "Error: no edges loaded from the file." << std::endl;
        return 1;
    }

    Solver solver(numVertices, edges);
    solver.solve();

    solver.printSolution();

    std::cout << "Press Enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
