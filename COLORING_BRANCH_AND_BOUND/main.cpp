#include "parser.h"
#include "solver.h"
#include <iostream>
#include <vector>

int main() {
    std::string filename;
    std::cout << "Enter the input file name: ";
    std::cin >> filename;

    Graph graph = parseGraphFromInput(filename);
    std::vector<int> coloring = edgeColoring(graph);

    std::cout << "Edge colors:" << std::endl;
    for (size_t i = 0; i < coloring.size(); ++i) {
        std::cout << "Edge " << i << " -> Color " << coloring[i] << std::endl;
    }

    std::cout << "Press Enter to exit...";
    std::cin.get(); 
    std::cin.get(); 
    return 0;
}
