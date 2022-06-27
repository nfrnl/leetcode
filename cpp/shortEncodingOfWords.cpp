// 820. Short Encoding of Words
// https://leetcode.com/problems/short-encoding-of-words/

#include <cassert>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int minimumLengthEncoding(std::vector<std::string>& words) {
        int result = 0;
        std::unordered_map<std::string_view, bool> encoded;

        for (const std::string_view word : words) {
            if (encoded.count(word)) {
                continue;
            }
            encoded.emplace(word, false);

            int i = 1;
            while (i < word.length()) {
                const std::string_view suffix = word.substr(i);

                const auto res = encoded.emplace(suffix, true);
                if (!res.second) {
                    if (res.first->second) {
                        i = static_cast<int>(word.length()); // we have to insert a full word there
                    }

                    res.first->second = true;
                    break;
                }

                i++;
            }

            result += i;
            if (i == word.length()) {
                result++;   // do not forget about '#' character
            }
        }
        return result;
    }
};

int main()
{
    std::vector<std::string> input1 = {"time", "me", "bell"};
    assert(Solution().minimumLengthEncoding(input1) == 10);

    std::vector<std::string> input2 = {"t"};
    assert(Solution().minimumLengthEncoding(input2) == 2);

    std::vector<std::string> input3 = {"me", "time"};
    assert(Solution().minimumLengthEncoding(input3) == 5);

    std::vector<std::string> input4 = {"time", "atime", "btime"};
    assert(Solution().minimumLengthEncoding(input4) == 12);
    return 0;
}