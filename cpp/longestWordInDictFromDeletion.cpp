// 524. Longest Word in Dictionary through Deleting
// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

#include <cassert>
#include <string>
#include <string_view>
#include <vector>

std::string findLongestWord(std::string s, std::vector<std::string>& d) {
	std::string result;
	for (std::string& ds : d) {
		std::string_view s_view(s);
		for (const char cur_char : ds) {
			const int i = s_view.find(cur_char);
			if (i == std::string_view::npos) {
				goto contin;
			}
			s_view.remove_prefix(i + 1);
		}
		if ((ds.length() > result.length()) || ((ds.length() == result.length()) && (ds < result))) {
			result = ds;
		}
		contin:;
	}
	return result;
}

int main() {
	const std::vector<std::string> dict1 = {"ale", "apple", "monkey", "plea"};
	assert(findLongestWord("abpcplea", dict1) == "apple");
	
	const std::vector<std::string> dict2 = {"a", "b", "c"};
	assert(findLongestWord("abpcplea", dict2) == "a");
	
	return 0;
}
