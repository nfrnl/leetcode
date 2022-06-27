// 1009. Complement of Base 10 Integer
// https://leetcode.com/problems/complement-of-base-10-integer/

#include <cassert>

int bitwiseComplement(int n) {
	const unsigned int complement = ~n;
	unsigned int width_mask = 1;
	n >>= 1;
	while (n) {
		width_mask = (width_mask << 1) | 1;
		n >>= 1;
	}
	return complement & width_mask;
}

int main()
{
	assert(bitwiseComplement(5) == 2);
	assert(bitwiseComplement(7) == 0);
	assert(bitwiseComplement(10) == 5);
	
	return 0;
}
