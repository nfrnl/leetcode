// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/

#include <cassert>
#include <numeric>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        int result = 0;
        const std::unordered_set<int> seen{nums.begin(), nums.end()};

        for (const int num : nums) {
            if (seen.count(num - 1)) {
                continue;
            }

            int current = num;
            int length = 1;
            while (seen.count(current + 1)) {
                current++;
                length++;
            }

            result = std::max(result, length);
        }

        return result;
    }
};

int main()
{
    std::vector<int> input1{100, 4, 200, 1, 3, 2};
    assert(Solution().longestConsecutive(input1) == 4);

    std::vector<int> input2{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    assert(Solution().longestConsecutive(input2) == 9);

    return 0;
}