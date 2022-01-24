# 226. Invert Binary Tree
# https://leetcode.com/problems/invert-binary-tree/

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __eq__(self, other):
        return other is not None and self.val == other.val and self.left == other.left and self.right == other.right


def invertTree(root: Optional[TreeNode]) -> Optional[TreeNode]:
    if root is None:
        return None
    root.left, root.right = root.right, root.left
    invertTree(root.left)
    invertTree(root.right)
    return root


if __name__ == '__main__':
    assert invertTree(TreeNode(2, left=TreeNode(1), right=TreeNode(3))) == TreeNode(
        2, left=TreeNode(3), right=TreeNode(1))
