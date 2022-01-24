# 1008. Construct Binary Search Tree from Preorder Traversal
# https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __eq__(self, other):
        return self.val == other.val and self.left.__eq__(other.left) and self.right.__eq__(other.right)


def bstFromPreorder(preorder: list[int]) -> Optional[TreeNode]:
    if not preorder:
        return None
    node_stack = []
    root = TreeNode(preorder[0])
    node_stack.append(root)
    for val in preorder[1:]:
        i = -1
        for n in node_stack:
            i += 1
            if val > n.val:
                break
        else:
            new_node = TreeNode(val)
            node_stack[i].left = new_node
            node_stack.append(new_node)
            continue
        new_node = TreeNode(val)
        node_stack[i].right = new_node
        node_stack[i:] = [new_node]
    return root


if __name__ == '__main__':
    expected = TreeNode(8, left=TreeNode(5, left=TreeNode(1), right=TreeNode(7)), right=TreeNode(10, left=None, right=(TreeNode(12))))
    res = bstFromPreorder([8, 5, 1, 7, 10, 12])
    assert res == expected
