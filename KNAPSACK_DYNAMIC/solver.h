#ifndef SOLVER_H
#define SOLVER_H

#include "parser.h"
#include <vector>

std::pair<int, std::vector<int>> solveKnapsackDynamic(const std::vector<Item>& items, int maxWeight);

#endif
