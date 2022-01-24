// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/

package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	traversedNodes := make(map[*ListNode]struct{})
	for iterNode := head; iterNode != nil; iterNode = iterNode.Next {
		if _, isIn := traversedNodes[iterNode]; isIn {
			return true
		} else {
			traversedNodes[iterNode] = struct{}{}
		}
	}
	return false
}

func main() {
	node0 := &ListNode{3, nil}
	node1 := &ListNode{2, nil}
	node2 := &ListNode{0, nil}
	node3 := &ListNode{-4, nil}
	node0.Next = node1
	node1.Next = node2
	node2.Next = node3
	node3.Next = node1

	fmt.Println(hasCycle(node0)) // true
}
