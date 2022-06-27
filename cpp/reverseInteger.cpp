// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/

#include <cassert>
#include <limits>

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            const int digit = x % 10;
            if (isOutOfBounds(digit, result)) {
                return 0;
            }

            result = result * 10 + digit;
            x /= 10;
        }
        return result;
    }
private:
    static bool isOutOfBounds(int last_digit, int other_digits) {
        static constexpr int max = std::numeric_limits<int>::max();
        static constexpr int max_last_digit = max % 10;
        static constexpr int max_other_digits = max / 10;

        static constexpr int min = std::numeric_limits<int>::min();
        static constexpr int min_last_digit = min % 10;
        static constexpr int min_other_digits = min / 10;

        return other_digits > max_other_digits || other_digits == max_other_digits && last_digit > max_last_digit
               || other_digits < min_other_digits || other_digits == min_other_digits && last_digit < min_last_digit;
    }
};

int main()
{
    assert(Solution().reverse(123) == 321);
    assert(Solution().reverse(-123) == -321);
    assert(Solution().reverse(120) == 21);
    assert(Solution().reverse(1463847413) == 0);
    assert(Solution().reverse(-1463847413) == 0);

    return 0;
}