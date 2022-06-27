// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

#include <algorithm>
#include <cassert>
#include <string>

class Solution {
public:
    int minPartitions(std::string n) {
        return charToInt(*std::max_element(n.begin(), n.end()));
    }
private:
    static int charToInt(char c) {
        return c - '0';
    }
};

int main()
{
    assert(Solution().minPartitions("32") == 3);

    assert(Solution().minPartitions("82734") == 8);

    assert(Solution().minPartitions("27346209830709182346") == 9);

    return 0;
}