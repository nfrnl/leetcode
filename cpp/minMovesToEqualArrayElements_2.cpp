// 462. Minimum Moves to Equal Array Elements II
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

class Solution {
public:
    int minMoves2(std::vector<int>& nums) {
        const std::size_t mid_point = nums.size() / 2;
        std::nth_element(nums.begin(), nums.begin() + mid_point, nums.end());
        const int median = nums[nums.size() / 2];

        int result = 0;
        for (const int n : nums) {
            result += std::abs(n - median);
        }
        return result;
    }
};

int main()
{
    std::vector<int> input1 = {1, 2, 3};
    assert(Solution().minMoves2(input1) == 2);

    std::vector<int> input2 = {1, 10, 2, 9};
    assert(Solution().minMoves2(input2) == 16);

    std::vector<int> input3 = {1, 0, 0, 8, 6};
    assert(Solution().minMoves2(input3) == 14);

    return 0;
}