# 105. Construct Binary Tree from Preorder and Inorder Traversal
# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

import timeit
from typing import Union


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def build_tree(preorder: list[int], inorder: list[int]) -> TreeNode:
    current_element = preorder.pop(0)
    result = TreeNode(current_element)
    elem_inorder_pos = inorder.index(current_element)
    if len(left_nodes := inorder[:elem_inorder_pos]) != 0:
        result.left = build_tree(preorder, left_nodes)
    if len(right_nodes := inorder[elem_inorder_pos+1:]) != 0:
        result.right = build_tree(preorder, right_nodes)
    return result


def build_tree_another(preorder: list[int], inorder: list[int]) -> TreeNode:
    inorder_indexes = {}
    for index, value in enumerate(inorder):
        inorder_indexes[value] = index
    preorder_index = 0

    def build_tree_inner(left: int, right: int) -> Union[TreeNode, None]:
        nonlocal preorder_index
        if left > right:
            return None
        elem_inorder_current = preorder[preorder_index]
        result = TreeNode(elem_inorder_current)
        preorder_index += 1
        result.left = build_tree_inner(left, inorder_indexes[elem_inorder_current] - 1)
        result.right = build_tree_inner(inorder_indexes[elem_inorder_current] + 1, right)
        return result

    return build_tree_inner(0, len(preorder) - 1)


if __name__ == '__main__':
    print(timeit.timeit("build_tree([3, 9, 20, 15, 7], [9, 3, 15, 20, 7])", globals=locals()))
    print(timeit.timeit("build_tree_another([3, 9, 20, 15, 7], [9, 3, 15, 20, 7])", globals=locals()))
