// 211. Design Add and Search Words Data Structure
// https://leetcode.com/problems/design-add-and-search-words-data-structure/

#include <cassert>
#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>

struct TrieNode {
    bool match(std::string_view pattern) const {
        if (pattern.empty()) {
            return is_complete;
        }
        const char c = pattern.front();
        if (c == '.') {
            for (const auto& [_, node] : next) {
                if (node->match(pattern.substr(1))) {
                    return true;
                }
            }
            return false;
        }
        auto it = next.find(c);
        if (it == next.end()) {
            return false;
        }
        return it->second->match(pattern.substr(1));
    }

    std::unordered_map<char, std::unique_ptr<TrieNode>> next;
    bool is_complete = false;
};

class WordDictionary {
private:
    TrieNode trie;
public:
    WordDictionary() = default;

    void addWord(std::string word) {
        auto* current_node = &trie;
        for (auto c : word) {
            auto& edges = current_node->next;
            auto it = edges.find(c);
            if (it == edges.end()) {
                it = edges.insert({ c, std::make_unique<TrieNode>() }).first;
            }
            current_node = it->second.get();
        }
        current_node->is_complete = true;
    }

    bool search(std::string word) {
        return trie.match(word);
    }
};

int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    assert(wordDictionary.search("pad") == false);
    assert(wordDictionary.search("bad") == true);
    assert(wordDictionary.search(".ad") == true);
    assert(wordDictionary.search("b..") == true);

    return 0;
}