// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/

#include <cassert>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> traversed;

        for (const int n : nums) {
            const auto [_, ok] = traversed.insert(n);
            if (!ok) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    std::vector<int> input1 = {1, 2, 3, 1};
    assert(Solution().containsDuplicate(input1) == true);

    std::vector<int> input2 = {1, 2, 3, 4};
    assert(Solution().containsDuplicate(input2) == false);

    std::vector<int> input3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    assert(Solution().containsDuplicate(input3) == true);

    return 0;
}