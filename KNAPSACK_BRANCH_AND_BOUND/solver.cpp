#include "solver.h"
#include <queue>
#include <algorithm>

struct Node {
    int level, profit, weight, bound;
    std::vector<bool> solution;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int bound(Node u, int n, int capacity, const std::vector<Item>& items) {
    if (u.weight >= capacity) 
        return 0;

    int profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;

    while ((j < n) && (totweight + items[j].weight <= capacity)) {
        totweight += items[j].weight;
        profit_bound += items[j].value;
        j++;
    }

    if (j < n) 
        profit_bound += (capacity - totweight) * items[j].value / items[j].weight;

    return profit_bound;
}

std::pair<int, std::vector<bool>> knapsackBranchAndBound(const std::vector<Item>& items, int capacity) {
    std::vector<Item> sortedItems = items;
    std::sort(sortedItems.begin(), sortedItems.end(), cmp);

    std::queue<Node> Q;
    Node u, v;
    
    u.level = -1;
    u.profit = u.weight = 0;
    u.solution.resize(items.size(), false);

    int maxProfit = 0;
    std::vector<bool> bestSolution(items.size(), false);
    
    Q.push(u);

    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        if (u.level == (int)items.size() - 1) 
            continue;

        v.level = u.level + 1;

        v.weight = u.weight + sortedItems[v.level].weight;
        v.profit = u.profit + sortedItems[v.level].value;
        v.solution = u.solution;
        v.solution[v.level] = true;

        if (v.weight <= capacity && v.profit > maxProfit) {
            maxProfit = v.profit;
            bestSolution = v.solution;
        }

        v.bound = bound(v, items.size(), capacity, sortedItems);

        if (v.bound > maxProfit)
            Q.push(v);

        v.weight = u.weight;
        v.profit = u.profit;
        v.solution[v.level] = false;

        v.bound = bound(v, items.size(), capacity, sortedItems);

        if (v.bound > maxProfit)
            Q.push(v);
    }

    return {maxProfit, bestSolution};
}
