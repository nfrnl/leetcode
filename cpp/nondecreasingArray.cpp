// 665. Non-decreasing Array
// https://leetcode.com/problems/non-decreasing-array/

#include <cassert>
#include <cstddef>
#include <vector>

class Solution {
public:
    bool checkPossibility(std::vector<int>& nums) {
        bool change_done = false;
        for (std::size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (change_done || (i > 0 && i < nums.size() - 2
                                    && nums[i - 1] > nums[i + 1]
                                    && nums[i + 2] < nums[i])) {
                    // in the second case we have to change at least two values
                    return false;
                }
                change_done = true;
            }
        }
        return true;
    }
};

int main() {
    std::vector<int> input1{4, 2, 3};
    assert(Solution().checkPossibility(input1) == true);

    std::vector<int> input2{4, 2, 1};
    assert(Solution().checkPossibility(input2) == false);

    std::vector<int> input3{3, 4, 2, 3};
    assert(Solution().checkPossibility(input3) == false);

    std::vector<int> input4{1, 2, 3, 4, 5, 2, 3, 4, 5};
    assert(Solution().checkPossibility(input4) == false);

    std::vector<int> input5{5, 7, 1, 8};
    assert(Solution().checkPossibility(input5) == true);

    return 0;
}