// 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>

class Solution {
public:
    int maxArea(int h, int w, std::vector<int>& horizontalCuts, std::vector<int>& verticalCuts) {
        const int max_height = getMaxCutInDimension(h, horizontalCuts);
        const int max_width = getMaxCutInDimension(w, verticalCuts);
        const long long int max_area = static_cast<long long int>(max_height) * max_width;

        static constexpr int modulo = 1000000007;
        return static_cast<int>(max_area % modulo);
    }
private:
    static int getMaxCutInDimension(int size, std::vector<int>& cuts) {
        std::sort(cuts.begin(), cuts.end());

        std::vector<int> heights{ cuts[0] };
        heights.reserve(cuts.size() + 1);

        for (std::size_t i = 1; i < cuts.size(); i++) {
            heights.push_back(cuts[i] - cuts[i - 1]);
        }
        heights.push_back(size - cuts[cuts.size() - 1]);

        return *std::max_element(heights.begin(), heights.end());
    }
};

int main() {
    std::vector<int> hor1{1, 2, 4};
    std::vector<int> vert1{1, 3};
    assert(Solution().maxArea(5, 4, hor1, vert1) == 4);

    std::vector<int> hor2{3, 1};
    std::vector<int> vert2{1};
    assert(Solution().maxArea(5, 4, hor2, vert2) == 6);

    std::vector<int> hor3{3};
    std::vector<int> vert3{3};
    assert(Solution().maxArea(5, 4, hor3, vert3) == 9);

    return 0;
}