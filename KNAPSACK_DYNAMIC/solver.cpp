#include "solver.h"
#include <vector>
#include <iostream>

std::pair<int, std::vector<int>> solveKnapsackDynamic(const std::vector<Item>& items, int maxWeight) {
    int n = items.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(maxWeight + 1, 0));
    std::vector<std::vector<bool>> take(n + 1, std::vector<bool>(maxWeight + 1, false));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= maxWeight; ++w) {
            if (items[i - 1].weight <= w) {
                int takeItem = items[i - 1].value + dp[i - 1][w - items[i - 1].weight];
                int leaveItem = dp[i - 1][w];
                if (takeItem > leaveItem) {
                    dp[i][w] = takeItem;
                    take[i][w] = true;
                } else {
                    dp[i][w] = leaveItem;
                }
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Восстанавливаем список выбранных предметов
    std::vector<int> selectedItems(n, 0);  // Вектор с 0 и 1
    int w = maxWeight;
    for (int i = n; i > 0; --i) {
        if (take[i][w]) {
            selectedItems[i - 1] = 1;  // Отмечаем предмет как выбранный
            w -= items[i - 1].weight;
        }
    }

    return {dp[n][maxWeight], selectedItems};
}
