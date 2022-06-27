// 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/

#include <cassert>
#include <string>
#include <string_view>
#include <vector>

bool isPalindrome(std::string_view str) {
	for (std::size_t i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}

void partition_dfs(std::vector<std::vector<std::string>>& result, std::string_view str,
	std::vector<std::string>& current)
{
	for (std::size_t end = 0; end < str.size(); ++end) {
		const auto iter_substr = str.substr(0, end + 1);
		if (isPalindrome(iter_substr)) {
			current.emplace_back(iter_substr);

			const auto next_substr = str.substr(end + 1);
			if (next_substr.empty()) {
				result.push_back(current);
			}
			else {
				partition_dfs(result, next_substr, current);
			}

			current.pop_back();
		}
	}
}

std::vector<std::vector<std::string>> partition(std::string s) {
	std::vector<std::vector<std::string>> result;
	std::vector<std::string> current;
	partition_dfs(result, s, current);
	return result;
}

int main() {
	const std::vector<std::vector<std::string>> res1 = { {"a", "a", "b"}, {"aa", "b"} };
	assert(partition("aab") == res1);
	const std::vector<std::vector<std::string>> res2 = { {"a"} };
	assert(partition("a") == res2);
	return 0;
}
