// 856. Score of Parentheses
// https://leetcode.com/problems/score-of-parentheses/

#include <cassert>
#include <stack>
#include <string>

int scoreOfParentheses(std::string S) {
	int iter_state = 0;
	std::stack<int> st;

	for (const char c : S) {
		if (c == '(') {
			st.push(iter_state);
			iter_state = 0;
		} else {
			iter_state = st.top() + ((iter_state == 0) ? 1 : 2 * iter_state);
			st.pop();
		}
	}

	return iter_state;
}

int main() {
	assert(scoreOfParentheses("()") == 1);
	assert(scoreOfParentheses("(())") == 2);
	assert(scoreOfParentheses("()()") == 2);
	
	return 0;
}
