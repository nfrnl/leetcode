// 476. Number Complement
// https://leetcode.com/problems/number-complement/

#include <cassert>

int findComplement(int num) {
    unsigned int leftmost_one_pos = 0;
    do {
        leftmost_one_pos++;
        num >>= 1;
    } while (num > 0);
    unsigned int mask = (1 << leftmost_one_pos) - 1;
    return ~num & mask;
}

int main()
{
    assert(findComplement(5) == 2);
    assert(findComplement(1) == 0);
	
	return 0;
}
