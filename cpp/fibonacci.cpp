// 509. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/

#include <cassert>

class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }

        int prev = 0;
        int cur = 1;
        for (int i = 1; i < n; i++) {
            const int t = cur;
            cur += prev;
            prev = t;
        }

        return cur;
    }
};

int main()
{
    assert(Solution().fib(2) == 1);
    assert(Solution().fib(3) == 2);
    assert(Solution().fib(4) == 3);
    assert(Solution().fib(0) == 0);
    assert(Solution().fib(1) == 1);

    return 0;
}