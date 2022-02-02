// 438. Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <array>
#include <cassert>
#include <string>
#include <vector>

std::size_t charToIndex(char c) {
    return c - 'a';
}

std::vector<int> findAnagrams(std::string s, std::string p) {
    if (p.length() > s.length()) {
        return {};
    }

    std::array<int, 26> target{};
    for (const auto c : p) {
        ++target[charToIndex(c)];
    }

    const std::size_t window_size = p.length();

    std::array<int, 26> check_window{};
    for (std::size_t i = 0; i < window_size; ++i) {
        ++check_window[charToIndex(s[i])];
    }

    std::vector<int> result;
    if (check_window == target) {
        result.push_back(0);
    }
    
    for (std::size_t i = 1; i < s.length() - window_size + 1; ++i) {
        --check_window[charToIndex(s[i - 1])];
        ++check_window[charToIndex(s[i + window_size - 1])];
        if (check_window == target) {
            result.push_back(static_cast<int>(i));
        }
    }
    return result;
}

int main()
{
    assert(findAnagrams("cbaebabacd", "abc") == std::vector<int>({0, 6}));
    assert(findAnagrams("abab", "ab") == std::vector<int>({ 0, 1, 2 }));

    return 0;
}
