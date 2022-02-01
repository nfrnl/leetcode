// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <algorithm>
#include <cassert>
#include <vector>

int maxProfit(std::vector<int>& prices) {
    int profit = 0;
    int minPrice = prices[0];
    for (const auto price : prices) {
        if (price < minPrice) {
            minPrice = price;
        }
        else {
            profit = std::max(profit, price - minPrice);
        }
    }
    return profit;
}

int main()
{
    {
        std::vector<int> input{ 7, 1, 5, 3, 6, 4 };
        assert(maxProfit(input) == 5);
    }
    {
        std::vector<int> input{ 7, 6, 4, 3, 1 };
        assert(maxProfit(input) == 0);
    }

    return 0;
}
