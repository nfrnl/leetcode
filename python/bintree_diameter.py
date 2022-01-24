# 543. Diameter of Binary Tree
# https://leetcode.com/problems/diameter-of-binary-tree/

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def diameterOfBinaryTree(root: Optional[TreeNode]) -> int:
    diameter, _ = _diameterOfBinaryTree(root)
    return diameter


def _diameterOfBinaryTree(root: Optional[TreeNode]) -> tuple[int, int]:
    """Returns diameter of the subtree and its depth."""
    if root is None:
        return 0, 0
    lt_diam, lt_depth = _diameterOfBinaryTree(root.left)
    rt_diam, rt_depth = _diameterOfBinaryTree(root.right)
    diameter = max(lt_diam, rt_diam, lt_depth + rt_depth)
    return diameter, max(lt_depth, rt_depth) + 1


if __name__ == '__main__':
    assert diameterOfBinaryTree(
        TreeNode(1, left=TreeNode(2, left=TreeNode(4), right=TreeNode(5)), right=TreeNode(3))) == 3
    assert diameterOfBinaryTree(TreeNode(1, left=TreeNode(2))) == 1
