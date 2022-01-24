// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/

package main

import "fmt"

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func rightSideView(root *TreeNode) []int {
	if root == nil {
		return []int{}
	} else {
		return rightSideViewTraversal(root)
	}
}

func rightSideViewTraversal(root *TreeNode) []int {
	result := []int{root.Val}

	if root.Left == nil && root.Right == nil {
		return result
	}
	if root.Left == nil {
		result = append(result, rightSideViewTraversal(root.Right)...)
		return result
	}
	if root.Right == nil {
		result = append(result, rightSideViewTraversal(root.Left)...)
		return result
	}

	leftRes := rightSideViewTraversal(root.Left)
	rightRes := rightSideViewTraversal(root.Right)

	if len(rightRes) >= len(leftRes) {
		result = append(result, rightSideViewTraversal(root.Right)...)
		return result
	}

	for i, n := range rightRes {
		leftRes[i] = n
	}
	result = append(result, leftRes...)
	return result
}

func main() {
	fmt.Println(rightSideView(&TreeNode{
		1, &TreeNode{
			2, nil, &TreeNode{
				5, nil, nil,
			},
		}, &TreeNode{
			3, nil, &TreeNode{
				4, nil, nil,
			},
		},
	}))
	fmt.Println(rightSideView(&TreeNode{
		1, &TreeNode{
			2, &TreeNode{
				4, nil, nil,
			}, nil,
		}, &TreeNode{
			3, nil, nil,
		},
	}))
}
