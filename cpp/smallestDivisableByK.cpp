// 1015. Smallest Integer Divisible by K
// https://leetcode.com/problems/smallest-integer-divisible-by-k/

#include <cassert>
#include <unordered_set>

int smallestRepunitDivByK(int k) {
	for (int rem = 1 % k, length = 1; length <= k; length++) {
		if (rem == 0) {
			return length;
		}
		rem = (rem * 10 + 1) % k;
	}
	return -1;
}

int main()
{
	assert(smallestRepunitDivByK(1) == 1);
	assert(smallestRepunitDivByK(2) == -1);
	assert(smallestRepunitDivByK(3) == 3);
	return 0;
}
