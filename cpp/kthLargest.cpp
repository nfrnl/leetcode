// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <cassert>
#include <queue>
#include <vector>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> largest_elements;

        for (const int num : nums) {
            largest_elements.push(num);
        }

        for (int i = 0; i < k - 1; i++) {
            largest_elements.pop();
        }
        return largest_elements.top();
    }
};

int main()
{
    std::vector<int> input1 = {3, 2, 1, 5, 6, 4};
    assert(Solution().findKthLargest(input1, 2) == 5);

    std::vector<int> input2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    assert(Solution().findKthLargest(input2, 4) == 4);

    return 0;
}