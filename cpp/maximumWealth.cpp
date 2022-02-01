// 1672. Richest Customer Wealth
// https://leetcode.com/problems/richest-customer-wealth/

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

int maximumWealth(std::vector<std::vector<int>>& accounts) {
    int wealth = 0;
    for (const auto& customer : accounts) {
        wealth = std::max(wealth, std::accumulate(customer.begin(), customer.end(), 0));
    }
    return wealth;
}

int main()
{
    {
        std::vector<std::vector<int>> input{ {1, 2, 3}, {3, 2, 1} };
        assert(maximumWealth(input) == 6);
    }
    {
        std::vector<std::vector<int>> input{ {1, 5}, {7, 3}, {3, 5} };
        assert(maximumWealth(input) == 10);
    }
    {
        std::vector<std::vector<int>> input{ {2, 8, 7}, {7, 1, 3}, {1, 9, 5} };
        assert(maximumWealth(input) == 17);
    }

    return 0;
}
