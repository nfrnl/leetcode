// 669. Trim a Binary Search Tree
// https://leetcode.com/problems/trim-a-binary-search-tree/

package leetcode

type TreeNode struct {
    Val int
    Left *TreeNode
	Right *TreeNode
}

func trimBST(root *TreeNode, low int, high int) *TreeNode {
	for {
		if root.Val < low {
			root = root.Right
		} else if root.Val > high {
			root = root.Left
		} else {
			break
		}
	}
	for curIter := root; curIter != nil && curIter.Left != nil; {
		if curIter.Left.Val < low {
			curIter.Left = curIter.Left.Right
		} else {
			curIter = curIter.Left
		}
	}
	for curIter := root; curIter != nil && curIter.Right != nil; {
		if curIter.Right.Val > high {
			curIter.Right = curIter.Right.Left
		} else {
			curIter = curIter.Right
		}
	}
	return root
}
