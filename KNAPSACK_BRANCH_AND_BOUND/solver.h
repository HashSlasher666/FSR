#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include "parser.h"

std::pair<int, std::vector<bool>> knapsackBranchAndBound(const std::vector<Item>& items, int capacity);

#endif
