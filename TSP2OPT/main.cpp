#include "parser.h"
#include "solver.h"
#include <iostream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    Parser parser(filename);

    std::vector<Point> points = parser.parseData();

    if (points.empty()) {
        std::cerr << "Error: no points loaded from the file." << std::endl;
        return 1;
    }

    Solver solver(points);
    solver.solve();

    solver.printSolution();

    std::cout << "Press Enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
