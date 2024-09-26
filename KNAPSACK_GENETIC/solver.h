#ifndef SOLVER_H
#define SOLVER_H

#include "parser.h"
#include <vector>

class Solver {
public:
    Solver(const std::vector<Item>& items, int capacity);
    void solve();
    void printSolution() const;

private:
    int fitness(const std::vector<int>& chromosome) const;
    std::vector<int> mutate(const std::vector<int>& chromosome) const;
    std::vector<int> crossover(const std::vector<int>& parent1, const std::vector<int>& parent2) const;
    std::vector<int> generateRandomChromosome() const;
    void selectNextGeneration();

    std::vector<Item> items;
    int capacity;
    std::vector<std::vector<int>> population;
    std::vector<int> bestChromosome;
    int bestFitness;
    const int populationSize = 100; 
    const int maxGenerations = 1000; 
};

#endif
