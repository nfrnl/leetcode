// 376. Wiggle Subsequence
// https://leetcode.com/problems/wiggle-subsequence/

#include <cassert>
#include <numeric>
#include <vector>

class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        int up = 1, down = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            } else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }

        return std::max(up, down);
    }
};

int main()
{
    std::vector<int> input1{1, 7, 4, 9, 2, 5};
    assert(Solution().wiggleMaxLength(input1) == 6);

    std::vector<int> input2{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    assert(Solution().wiggleMaxLength(input2) == 7);

    std::vector<int> input3{1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(Solution().wiggleMaxLength(input3) == 2);

    return 0;
}