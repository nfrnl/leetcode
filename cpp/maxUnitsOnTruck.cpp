// 1710. Maximum Units on a Truck
// https://leetcode.com/problems/maximum-units-on-a-truck/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

class Solution {
public:
    int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(),
                  [](const auto& l, const auto& r){ return l[1] > r[1]; });

        int result = 0;
        int spaceLeft = truckSize;

        for (const auto& boxType : boxTypes) {
            const int boxTypeCount = boxType[0];
            const int loadCount = std::min(boxTypeCount, spaceLeft);
            result += boxType[1] * loadCount;

            spaceLeft -= loadCount;
            if (spaceLeft == 0) {
                break;
            }
        }

        return result;
    }
};

int main()
{
    std::vector<std::vector<int>> input1{{1, 3}, {2, 2}, {3, 1}};
    assert(Solution().maximumUnits(input1, 4) == 8);

    std::vector<std::vector<int>> input2{{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    assert(Solution().maximumUnits(input2, 10) == 91);

    return 0;
}