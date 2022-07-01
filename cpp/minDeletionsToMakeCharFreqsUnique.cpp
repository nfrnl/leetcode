// 1647. Minimum Deletions to Make Character Frequencies Unique
// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <functional>
#include <string>

class Solution {
public:
    int minDeletions(std::string s) {
        std::array<int, char_count> char_frequencies{};
        for (const char c : s) {
            char_frequencies[charToIndex(c)]++;
        }

        std::sort(char_frequencies.begin(), char_frequencies.end(), std::greater{});

        int result = 0;
        for (int i = 1; i < char_frequencies.size(); i++) {
            if (char_frequencies[i] == 0) {
                break;
            }

            int allowed = std::max(char_frequencies[i - 1] - 1, 0);
            if (char_frequencies[i] > allowed) {
                result += char_frequencies[i] - allowed;
                char_frequencies[i] = allowed;
            }
        }

        return result;
    }

private:
    static constexpr std::size_t char_count = 'z' - 'a' + 1;

    static std::size_t charToIndex(char c) {
        return c - 'a';
    }
};

int main()
{
    assert(Solution().minDeletions("aab") == 0);
    assert(Solution().minDeletions("aaabbbcc") == 2);
    assert(Solution().minDeletions("ceabaacb") == 2);
    assert(Solution().minDeletions("bbcebab") == 2);

    return 0;
}