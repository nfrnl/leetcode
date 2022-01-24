// 198. House Robber
// https://leetcode.com/problems/house-robber/

#include <algorithm>
#include <cassert>
#include <vector>

int rob(std::vector<int>& nums) {
    const auto count = nums.size();
    if (count == 1) {
        return nums[0];
    }
    std::vector<int> dp(count);
    dp[count - 1] = nums.back();
    dp[count - 2] = std::max(nums.back(), nums[count - 2]);
    for (int i = count - 3; i >= 0; --i) {
        dp[i] = std::max(dp[i + 1], nums[i] + dp[i + 2]);
    }
    return dp[0];
}

int main()
{
    std::vector<int> input1{ 1, 2, 3, 1 };
    assert(rob(input1) == 4);

    std::vector<int> input2{ 2, 7, 9, 3, 1 };
    assert(rob(input2) == 12);

    std::vector<int> input3{ 0 };
    assert(rob(input3) == 0);

    std::vector<int> input4{ 4, 3 };
    assert(rob(input4) == 4);

    return 0;
}
