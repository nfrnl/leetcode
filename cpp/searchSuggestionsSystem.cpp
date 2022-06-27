// 1268. Search Suggestions System
// https://leetcode.com/problems/search-suggestions-system/

#include <array>
#include <cassert>
#include <string>
#include <string_view>
#include <tuple>
#include <utility>
#include <vector>
#include <memory>

using std::vector;
using std::string;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        std::vector<std::vector<std::string>> result;

        Trie trie;
        for (const std::string_view product : products) {
            trie.insert(product);
        }

        const std::string_view searchWordView{searchWord};
        for (int i = 0; i < searchWord.size(); i++) {
            std::string_view query = searchWordView.substr(0, i + 1);
            result.emplace_back(trie.getStartingWith(query, 3));
        }
        return result;
    }
private:
    struct Trie {
        bool isWord = false;
        static constexpr std::size_t nextCount = 'z' - 'a' + 1;
        std::array<std::unique_ptr<Trie>, nextCount> next;

        static std::size_t toIndex(char c) {
            return c - 'a';
        }

        static char toChar(std::size_t i) {
            return 'a' + i;
        }

        void insert(std::string_view word) {
            Trie* current = this;
            for (const char c : word) {
                std::size_t i = toIndex(c);
                if (!current->next[i]) {
                    current->next[i] = std::make_unique<Trie>();
                }
                current = current->next[i].get();
            }
            current->isWord = true;
        }

        std::vector<std::string> getStartingWith(std::string_view prefix, int limit) const {
            const Trie* current = this;
            for (const char c : prefix) {
                std::size_t i = toIndex(c);
                if (!current->next[i]) {
                    return {};
                }
                current = current->next[i].get();
            }
            return current->depthFirst(prefix, limit);
        }

        std::vector<std::string> depthFirst(std::string_view prefix, int limit) const {
            std::vector<std::string> result;
            result.reserve(limit);

            const Trie* curNode = this;
            std::string curPrefix{prefix};

            if (curNode->isWord) {
                result.emplace_back(prefix);
                if (limit == 1) {
                    return result;
                }
            }

            std::vector<std::pair<Trie*, std::string>> nodeStack;
            do {
                for (int i = static_cast<int>(curNode->next.size() - 1); i >= 0 ; i--) {
                    const auto& node = curNode->next[i];
                    if (node) {
                        nodeStack.emplace_back(node.get(), curPrefix + toChar(i));
                    }
                }

                if (nodeStack.empty()) {
                    break;
                }
                auto& pair = nodeStack.back();
                std::tie(curNode, curPrefix) = std::move(nodeStack.back());
                nodeStack.pop_back();

                if (curNode->isWord) {
                    result.push_back(curPrefix);
                }
            } while (result.size() < limit);

            return result;
        }
    };
};

int main()
{
    std::vector<std::string> products1 = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    const std::vector<std::vector<std::string>> output1 = {
            {"mobile", "moneypot", "monitor"},
            {"mobile", "moneypot", "monitor"},
            {"mouse", "mousepad"},
            {"mouse", "mousepad"},
            {"mouse", "mousepad"}
    };
    assert(Solution().suggestedProducts(products1, "mouse") == output1);

    std::vector<std::string> products2 = {"havana"};
    const std::vector<std::vector<std::string>> output2 = {
            {"havana"},
            {"havana"},
            {"havana"},
            {"havana"},
            {"havana"},
            {"havana"}
    };
    assert(Solution().suggestedProducts(products2, "havana") == output2);

    std::vector<std::string> products3 = {"bags", "baggage", "banner", "box", "cloths"};
    std::vector<std::vector<std::string>> output3 = {
            {"baggage", "bags", "banner"},
            {"baggage", "bags", "banner"},
            {"baggage", "bags"},
            {"bags"}
    };
    assert(Solution().suggestedProducts(products3, "bags") == output3);

    return 0;
}