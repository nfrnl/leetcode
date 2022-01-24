# 92. Reverse Linked List II
# https://leetcode.com/problems/reverse-linked-list-ii/

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def reverse_between(head: ListNode, left: int, right: int) -> ListNode:
    result_head = ListNode()
    cur_result_node = result_head
    cur_node = head
    i = 1
    cur_rev_node = None
    rt_rev_node = None
    while cur_node is not None:
        if i < left or i > right or i == left and i == right:
            cur_result_node.next = ListNode(cur_node.val)
            cur_result_node = cur_result_node.next
        elif left < i < right:
            cur_rev_node = ListNode(cur_node.val, cur_rev_node)
        else:
            if i == left:
                rt_rev_node = ListNode(cur_node.val)
                cur_rev_node = rt_rev_node
            if i == right:
                cur_result_node.next = ListNode(cur_node.val, cur_rev_node)
                cur_result_node = rt_rev_node
        cur_node = cur_node.next
        i += 1
    return result_head.next


if __name__ == '__main__':
    ll = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5, None)))))
    res_ll = ListNode(1, ListNode(4, ListNode(3, ListNode(2, ListNode(5, None)))))
    func_res = reverse_between(ll, 2, 4)
    assert(func_res.val == res_ll.val and func_res.next.val == func_res.next.val and
           func_res.next.next.val == func_res.next.next.val and func_res.next.next.next.val == func_res.next.next.next.val)
    assert(reverse_between(ListNode(5, None), 1, 1).val == 5)
