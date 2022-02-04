// 525. Contiguous Array
// https://leetcode.com/problems/contiguous-array/

#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <vector>

int findMaxLength(std::vector<int>& nums) {
    std::unordered_map<int, int> variance_indexes;
    variance_indexes.insert({ 0, -1 });
    int max_length = 0;
    int current_variance = 0;
    for (int i = 0; i < nums.size(); ++i) {
        current_variance += nums[i] ? 1 : -1;
        if (const auto it = variance_indexes.find(current_variance); it != variance_indexes.end()) {
            max_length = std::max(max_length, i - it->second);
        }
        else {
            variance_indexes.insert({ current_variance, i });
        }
    }
    return max_length;
}

int main()
{
    {
        std::vector<int> input{ 0, 1 };
        assert(findMaxLength(input) == 2);
    }
    {
        std::vector<int> input{ 0, 1, 0 };
        assert(findMaxLength(input) == 2);
    }

    return 0;
}
