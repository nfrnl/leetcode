// 135. Candy
// https://leetcode.com/problems/candy/

#include <cassert>
#include <numeric>
#include <vector>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        std::vector<int> candies(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = ratings.size() - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) {
                candies[i - 1] = std::max(candies[i - 1], candies[i] + 1);
            }
        }

        return std::accumulate(candies.begin(), candies.end(), 0);
    }
};
int main()
{
    std::vector<int> input1{1, 0, 2};
    assert(Solution().candy(input1) == 5);

    std::vector<int> input2{1, 2, 2};
    assert(Solution().candy(input2) == 4);

    return 0;
}