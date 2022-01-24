// 84. Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <algorithm>
#include <cassert>
#include <vector>

int largestRectangleArea(std::vector<int>& heights) {
    heights.push_back(0);
    std::vector<int> stack;
    int area = 0;
    for (int i = 0; i < heights.size(); i++) {
        while (!stack.empty() && heights[stack.back()] >= heights[i]) {
            const auto height = heights[stack.back()];
            stack.pop_back();
            const auto width = stack.empty() ? i : (i - stack.back() - 1);
            area = std::max(area, height * width);
        }
        stack.push_back(i);
    }
    return area;
}

int main()
{
    std::vector<int> input1{ 2, 1, 5, 6, 2, 3 };
    assert(largestRectangleArea(input1) == 10);

    std::vector<int> input2{ 2, 4 };
    assert(largestRectangleArea(input2) == 4);

    return 0;
}
