#include "solver.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <numeric>


Solver::Solver(const std::vector<Item>& items, int capacity)
    : items(items), capacity(capacity), bestFitness(0) {
    srand(time(0)); 
}


int Solver::fitness(const std::vector<int>& chromosome) const {
    int totalValue = 0, totalWeight = 0;
    for (size_t i = 0; i < chromosome.size(); ++i) {
        if (chromosome[i] == 1) {
            totalValue += items[i].value;
            totalWeight += items[i].weight;
        }
    }
    if (totalWeight > capacity) {
        return 0; 
    }
    return totalValue;
}


std::vector<int> Solver::mutate(const std::vector<int>& chromosome) const {
    std::vector<int> mutatedChromosome = chromosome;
    int mutationPoint = rand() % chromosome.size();
    mutatedChromosome[mutationPoint] = 1 - mutatedChromosome[mutationPoint];

    if (fitness(mutatedChromosome) == 0) {
        return chromosome;
    }
    return mutatedChromosome;
}

std::vector<int> Solver::crossover(const std::vector<int>& parent1, const std::vector<int>& parent2) const {
    int crossoverPoint = rand() % parent1.size();
    std::vector<int> child(parent1.size());

    for (int i = 0; i < crossoverPoint; ++i) {
        child[i] = parent1[i];
    }
    for (size_t i = crossoverPoint; i < parent2.size(); ++i) {
        child[i] = parent2[i];
    }

    if (fitness(child) == 0) {
        return (rand() % 2 == 0) ? parent1 : parent2;
    }

    return child;
}


std::vector<int> Solver::generateRandomChromosome() const {
    std::vector<int> chromosome(items.size(), 0);
    int currentWeight = 0;

    std::vector<int> indices(items.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::random_shuffle(indices.begin(), indices.end());

    for (int i : indices) {
        if (currentWeight + items[i].weight <= capacity) {
            chromosome[i] = 1;
            currentWeight += items[i].weight;
        }
    }

    return chromosome;
}

void Solver::selectNextGeneration() {
    std::sort(population.begin(), population.end(),
              [this](const std::vector<int>& a, const std::vector<int>& b) {
                  return fitness(a) > fitness(b);
              });
    population.resize(populationSize);
}

void Solver::solve() {
    for (int i = 0; i < populationSize; ++i) {
        population.push_back(generateRandomChromosome());
    }

    for (int generation = 0; generation < maxGenerations; ++generation) {
        selectNextGeneration();

        std::vector<std::vector<int>> newPopulation;
        while (newPopulation.size() < populationSize) {
            int parent1Idx = rand() % populationSize;
            int parent2Idx = rand() % populationSize;
            std::vector<int> child = crossover(population[parent1Idx], population[parent2Idx]);
            child = mutate(child);
            newPopulation.push_back(child);
        }

        population = newPopulation;
    }

    bestChromosome = population[0];
    bestFitness = fitness(bestChromosome);
}

void Solver::printSolution() const {
    std::cout << bestFitness << std::endl;
    for (int gene : bestChromosome) {
        std::cout << gene << " ";
    }
    std::cout << std::endl;
}
