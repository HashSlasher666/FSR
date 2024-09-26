#include "parser.h"
#include "solver.h"
#include <iostream>
#include <string>

int main() {
    // Запрос имени файла у пользователя
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    // Передаем имя файла в парсер
    Parser parser(filename);

    // Читаем данные
    std::vector<Point> points = parser.parseData();

    if (points.empty()) {
        std::cerr << "Error: no points loaded from the file." << std::endl;
        return 1;
    }

    // Решаем задачу
    Solver solver(points);
    solver.solve();

    // Выводим решение
    solver.printSolution();

    // Заглушка для консоли
    std::cout << "Press Enter to exit...";
    std::cin.ignore();  // Игнорируем остатки символов в буфере
    std::cin.get();

    return 0;
}
