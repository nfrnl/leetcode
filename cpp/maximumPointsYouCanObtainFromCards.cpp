// 1423. Maximum Points You Can Obtain from Cards
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

class Solution {
public:
    int maxScore(std::vector<int>& cardPoints, int k) {
        int current_window = std::accumulate(cardPoints.begin(),
                                             cardPoints.begin() + k,
                                             0);

        int result = current_window;
        for (int i = 0; i < k; i++) {
            current_window -= cardPoints[k - 1 - i];
            current_window += cardPoints[cardPoints.size() - 1 - i];

            result = std::max(result, current_window);
        }

        return result;
    }
};

int main() {
    std::vector<int> input1{1, 2, 3, 4, 5, 6, 1};
    assert(Solution().maxScore(input1, 3) == 12);

    std::vector<int> input2{2, 2, 2};
    assert(Solution().maxScore(input2, 2) == 4);

    std::vector<int> input3{9, 7, 7, 9, 7, 7, 9};
    assert(Solution().maxScore(input3, 7) == 55);

    return 0;
}