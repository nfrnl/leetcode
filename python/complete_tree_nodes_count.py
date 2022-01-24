# 222. Count Complete Tree Nodes
# https://leetcode.com/problems/count-complete-tree-nodes/

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def height(root: Optional[TreeNode]) -> int:
    if root is None:
        return -1
    return height(root.left) + 1


def countNodes(root: Optional[TreeNode]) -> int:
    full_ht = height(root)
    if full_ht < 0:
        return 0

    rt_subtree_ht = height(root.right)
    if rt_subtree_ht == full_ht - 1:
        return (1 << full_ht) + countNodes(root.right)
    else:
        return (1 << full_ht - 1) + countNodes(root.left)


if __name__ == '__main__':
    assert countNodes(TreeNode(
        1, left=TreeNode(2, left=TreeNode(4), right=TreeNode(5)), right=TreeNode(3, left=TreeNode(6)))) == 6
    assert countNodes(None) == 0
    assert countNodes(TreeNode(1)) == 1
