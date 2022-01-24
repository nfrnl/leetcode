// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/

#include <algorithm>
#include <cassert>
#include <vector>

int maxArea(std::vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int max_area = 0;
    while (i < j) {
        const int h = std::min(height[i], height[j]);
        max_area = std::max(max_area, (j - i) * h);
        while (height[i] <= h && i < j) {
            i++;
        }
        while (height[j] <= h && i < j) {
            j--;
        }
    }
    return max_area;
}

int main()
{
    std::vector<int> input1{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    assert(maxArea(input1) == 49);

    std::vector<int> input2{ 1, 1 };
    assert(maxArea(input2) == 1);

    return 0;
}
