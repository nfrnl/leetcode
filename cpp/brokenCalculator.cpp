// 991. Broken Calculator
// https://leetcode.com/problems/broken-calculator/

#include <cassert>

int brokenCalc(int X, int Y) {
	int result = 0;
	while (Y > X) {
		result++;
		if (Y % 2 > 0) {
			Y++;
		} else {
			Y /= 2;
		}
	}
	return X - Y + result;
}

int main() {
	assert(brokenCalc(2, 3) == 2);
	assert(brokenCalc(5, 8) == 2);
	assert(brokenCalc(3, 10) == 3);
	
	return 0;
}
