# 993. Cousins in Binary Tree
# https://leetcode.com/problems/cousins-in-binary-tree/

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def _find_in(val: int, cousins: list[TreeNode]):
    for node in cousins:
        if node.val == val:
            return True
    return False


def isCousins(root: Optional[TreeNode], x: int, y: int) -> bool:
    queue = [[root]]
    while len(queue) > 0:
        next_queue = []
        for i, siblings in enumerate(queue):
            for j, sibling in enumerate(siblings):
                n_queue_batch = []
                if sibling.val == x:
                    if j < len(siblings) - 1 and siblings[j + 1] == y:
                        return False
                    return _find_in(y, [node for siblings in queue[i + 1:] for node in siblings])
                elif sibling.val == y:
                    if j < len(siblings) - 1 and siblings[j + 1] == x:
                        return False
                    return _find_in(x, [node for siblings in queue[i + 1:] for node in siblings])
                if sibling.left:
                    n_queue_batch.append(sibling.left)
                if sibling.right:
                    n_queue_batch.append(sibling.right)
                if n_queue_batch:
                    next_queue.append(n_queue_batch)
        queue = next_queue
    return False


if __name__ == '__main__':
    assert isCousins(
        TreeNode(1, left=TreeNode(2, left=TreeNode(4)), right=TreeNode(3)), 4, 3) is False
    assert isCousins(
        TreeNode(1, left=TreeNode(2, right=TreeNode(4)), right=TreeNode(3, right=TreeNode(5))), 5, 4) is True
    assert isCousins(
        TreeNode(1, left=TreeNode(2, right=TreeNode(4)), right=TreeNode(3)), 2, 3) is False
