// 406. Queue Reconstruction by Height
// https://leetcode.com/problems/queue-reconstruction-by-height/

#include <algorithm>
#include <cassert>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
        std::sort(people.begin(), people.end(), [](const auto& l, const auto& r){
            return (l[0] == r[0]) ? l[1] < r[1] : l[0] > r[0]; });

        std::vector<std::vector<int>> result;
        result.reserve(people.size());
        for (const auto& p: people) {
            result.insert(result.begin() + p[1], p);
        }

        return result;
    }
};

int main()
{
    std::vector<std::vector<int>> input1{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    const std::vector<std::vector<int>> output1{{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}};
    assert(Solution().reconstructQueue(input1) == output1);

    std::vector<std::vector<int>> input2{{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
    const std::vector<std::vector<int>> output2{{4,0},{5,0},{2,2},{3,2},{1,4},{6,0}};
    assert(Solution().reconstructQueue(input2) == output2);

    return 0;
}