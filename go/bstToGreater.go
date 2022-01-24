// 538. Convert BST to Greater Tree
// https://leetcode.com/problems/convert-bst-to-greater-tree/

package main

import "fmt"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func convertBSTiter(root *TreeNode, accumulator int) (int, *TreeNode) {
	newNode := &TreeNode{}
	var tree *TreeNode
	if root.Right != nil {
		accumulator, tree = convertBSTiter(root.Right, accumulator)
		newNode.Right = tree
	}
	accumulator += root.Val
	newNode.Val = accumulator
	if root.Left != nil {
		accumulator, tree = convertBSTiter(root.Left, accumulator)
		newNode.Left = tree
	}
	return accumulator, newNode
}

func convertBST(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	_, tree := convertBSTiter(root, 0)
	return tree
}

func main() {
	fmt.Println(convertBST(&TreeNode{
		1, &TreeNode{
			0, nil, nil,
		}, &TreeNode{
			2, nil, nil,
		},
	}))
}
