// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/

#include <cassert>
#include <functional>
#include <queue>
#include <utility>
#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    ListNode head;
    ListNode* tail = &head;
    using ValNode = std::pair<int, ListNode*>;
    std::priority_queue<ValNode, std::vector<ValNode>, std::greater<>> q;
    for (auto node : lists) {
        if (node) {
            q.push(std::make_pair(node->val, node));
        }
    }
    while (!q.empty()) {
        auto [val, node] = q.top();
        q.pop();
        tail->next = node;
        tail = tail->next;
        if (node->next) {
            q.push(std::make_pair(node->next->val, node->next));
        }
    }
    return head.next;
}


int main()
{
    {
        ListNode list1_node3{ 5 };
        ListNode list1_node2{ 4, &list1_node3 };
        ListNode list1_node1{ 1, &list1_node2 };
        ListNode list2_node3{ 4 };
        ListNode list2_node2{ 3, &list2_node3 };
        ListNode list2_node1{ 1, &list2_node2 };
        ListNode list3_node2{ 6 };
        ListNode list3_node1{ 2, &list3_node2 };
        std::vector<ListNode*> input{ &list1_node1, &list2_node1, &list3_node1 };
        const std::vector<int> expected{ 1, 1, 2, 3, 4, 4, 5, 6 };
        auto current = mergeKLists(input);
        int i = 0;
        while (current) {
            assert(current->val == expected[i]);
            current = current->next;
            ++i;
        }
    }
    {
        std::vector<ListNode*> input;
        assert(mergeKLists(input) == nullptr);
    }

    return 0;
}
