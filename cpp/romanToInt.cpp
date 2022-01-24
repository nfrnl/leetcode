// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

#include <cassert>
#include <string>

int romCharToInt(char c) {
	switch (c) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
	}
}

int romanToInt(std::string s) {
	if (s.length() == 0) {
		return 0;
	}

	int result = 0;
	int prev_char_val = 0;
	for (const char cur_char : s) {
		const int cur_char_val = romCharToInt(cur_char);
		if ((((cur_char == 'V') || (cur_char == 'X')) && (prev_char_val == 1)) ||
		  (((cur_char == 'L') || (cur_char == 'C')) && (prev_char_val == 10)) ||
		  (((cur_char == 'D') || (cur_char == 'M')) && (prev_char_val == 100))) {
			result += cur_char_val - prev_char_val;
			prev_char_val = 0;
		} else {
			result += prev_char_val;
			prev_char_val = cur_char_val;
		}
	}
	result += prev_char_val;

	return result;
}

int main() {
	assert(romanToInt("III") == 3);
	assert(romanToInt("LVIII") == 58);
	assert(romanToInt("MCMXCIV") == 1994);
	
	return 0;
}
