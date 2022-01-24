// 721. Accounts Merge
// https://leetcode.com/problems/accounts-merge/

#include <algorithm>
#include <cassert>
#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using Account = std::vector<std::string>;

void emailsDFS(Account& merged, const std::string& first_email,
    const std::unordered_map<std::string, std::vector<std::string>>& adjacent,
    std::unordered_set<std::string>& visited)
{
    std::deque<std::string> queue { first_email };
    while (!queue.empty()) {
        const auto email = std::move(queue.front());
        queue.pop_front();

        if (visited.count(email)) {
            continue;
        }

        visited.insert(email);
        merged.push_back(email);

        const auto it = adjacent.find(email);
        if (it == adjacent.end()) {
            return;
        }

        for (const auto& neighbor : it->second) {
            queue.push_back(neighbor);
        }
    }
}

std::vector<Account> accountsMerge(std::vector<Account>& accounts) {
    std::unordered_map<std::string, std::vector<std::string>> adjacent;
    for (const auto& account : accounts) {
        const auto& first_email = account[1];
        for (int i = 2; i < account.size(); i++) {
            const auto& email = account[i];
            adjacent[first_email].push_back(email);
            adjacent[email].push_back(first_email);
        }
    }

    std::unordered_set<std::string> visited;
    std::vector<Account> merged_accounts;
    for (const auto& account : accounts) {
        const auto& name = account[0];
        const auto& first_email = account[1];

        if (!visited.count(first_email)) {
            Account merged { name };
            emailsDFS(merged, first_email, adjacent, visited);
            std::sort(merged.begin() + 1, merged.end());
            merged_accounts.push_back(std::move(merged));
        }
    }
    return merged_accounts;
}

int main()
{
    std::vector<std::vector<std::string>> accounts1{
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };
    std::vector<std::vector<std::string>> expected1{
        {"John", "john00@mail.com", "john_newyork@mail.com",
        "johnsmith@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };
    assert(accountsMerge(accounts1) == expected1);

    std::vector<std::vector<std::string>> accounts2{
        {"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},
        {"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},
        {"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},
        {"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},
        {"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}
    };
    std::vector<std::vector<std::string>> expected2{
        {"Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"},
        {"Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"},
        {"Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"},
        {"Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"},
        {"Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"}
    };
    assert(accountsMerge(accounts2) == expected2);

    return 0;
}
