// 1354. Construct Target Array With Multiple Sums
// https://leetcode.com/problems/construct-target-array-with-multiple-sums/

#include <cassert>
#include <queue>
#include <vector>

class Solution {
public:
    bool isPossible(std::vector<int>& target) {
        if (target.size() == 1) {
            return target[0] == 1;
        }

        long long int sum = 0;
        std::priority_queue<int> arrayElements;
        for (const int x : target) {
            sum += x;
            arrayElements.push(x);
        }

        while (arrayElements.top() != 1) {
            const int maxElement = arrayElements.top();

            const long long int allWithoutMax = sum - maxElement;
            if (allWithoutMax == 1) {
                // this may only happen when we are given an array of two elements
                // in this case, the other element has a value of one which may be
                // subtracted from maxElement until it has a value of zero
                // however, the target array is actually constructible in this case,
                // so return now with the correct answer as otherwise the prevMax
                // would become 0, leading to an incorrect return value
                return true;
            }

            const int prevMax = maxElement % allWithoutMax;
            if (prevMax == 0 || prevMax == maxElement) {
                return false;
            }

            sum = allWithoutMax + prevMax;
            arrayElements.pop();
            arrayElements.push(prevMax);
        }

        return true;
    }
};

int main() {
    std::vector<int> input1{9, 3, 5};
    assert(Solution().isPossible(input1) == true);

    std::vector<int> input2{1, 1, 1, 2};
    assert(Solution().isPossible(input2) == false);

    std::vector<int> input3{8, 5};
    assert(Solution().isPossible(input3) == true);

    std::vector<int> input4{2};
    assert(Solution().isPossible(input4) == false);

    return 0;
}
