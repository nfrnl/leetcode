// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/

#include <algorithm>
#include <cassert>
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int result = 0;
        int left = 0, right = static_cast<int>(height.size() - 1);
        int left_max = height[left], right_max = height[right];
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] < left_max) {
                    result += left_max - height[left];
                }
                left_max = std::max(left_max, height[left]);
                left++;
            } else {
                if (height[right] < right_max) {
                    result += right_max - height[right];
                }
                right_max = std::max(right_max, height[right]);
                right--;
            }
        }
        return result;
    }
};

int main()
{
    std::vector<int> input1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    assert(Solution().trap(input1) == 6);

    std::vector<int> input2 = {4, 2, 0, 3, 2, 5};
    assert(Solution().trap(input2) == 9);

    return 0;
}