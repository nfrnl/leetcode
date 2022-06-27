// 1642. Furthest Building You Can Reach
// https://leetcode.com/problems/furthest-building-you-can-reach/

#include <cassert>
#include <queue>
#include <vector>

class Solution {
public:
    int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
        std::priority_queue<int> used_blocks;

        int i;
        for (i = 0; i < heights.size() - 1; i++) {
            const int bricks_diff = heights[i + 1] - heights[i];
            if (bricks_diff <= 0) {
                continue;
            }

            used_blocks.push(bricks_diff);
            bricks -= bricks_diff;

            while (bricks < 0 && !used_blocks.empty()) {
                if (ladders == 0) {
                    return i;
                }

                bricks += used_blocks.top();
                used_blocks.pop();
                ladders--;
            }
        }

        return i;
    }
};

int main()
{
    std::vector<int> input1 = {4, 2, 7, 6, 9, 14, 12};
    assert(Solution().furthestBuilding(input1, 5, 1) == 4);

    std::vector<int> input2 = {4, 12, 2, 7, 3, 18, 20, 3, 19};
    assert(Solution().furthestBuilding(input2, 10, 2) == 7);

    std::vector<int> input3 = {14, 3, 19, 3};
    assert(Solution().furthestBuilding(input3, 17, 0) == 3);
    return 0;
}