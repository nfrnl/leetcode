// 138. Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/

package main

import (
	"fmt"
	"strconv"
	"strings"
)

type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

func copyRandomList(head *Node) *Node {
	if head == nil {
		return nil
	}

	oldToNew := make(map[*Node]*Node)
	newList := &Node{head.Val, nil, nil}
	oldToNew[head] = newList

	for iter, newIter := head.Next, newList; iter != nil; iter, newIter = iter.Next, newIter.Next {
		newNode := &Node{iter.Val, nil, nil}
		oldToNew[iter] = newNode
		newIter.Next = newNode
	}

	for iter, newIter := head, newList; iter != nil; iter, newIter = iter.Next, newIter.Next {
		newIter.Random = oldToNew[iter.Random]
	}

	return newList
}

func printList(head *Node) string {
	indexes := make(map[*Node]int)
	for i, node := 0, head; node != nil; i, node = i+1, node.Next {
		indexes[node] = i
	}
	var sb strings.Builder
	sb.WriteByte('[')
	for node := head; node != nil; node = node.Next {
		random := "null"
		if node.Random != nil {
			random = strconv.Itoa(indexes[node.Random])
		}
		fmt.Fprintf(&sb, "[%d,%s]", node.Val, random)
		if node.Next != nil {
			sb.WriteByte(',')
		}
	}
	sb.WriteByte(']')
	return sb.String()
}

func main() {
	list1Node1 := &Node{7, nil, nil}
	list1Node2 := &Node{13, nil, nil}
	list1Node3 := &Node{11, nil, nil}
	list1Node4 := &Node{10, nil, nil}
	list1Node5 := &Node{1, nil, nil}
	list1Node1.Next = list1Node2
	list1Node2.Next = list1Node3
	list1Node2.Random = list1Node1
	list1Node3.Next = list1Node4
	list1Node3.Random = list1Node5
	list1Node4.Next = list1Node5
	list1Node4.Random = list1Node3
	list1Node5.Random = list1Node1
	newList1 := copyRandomList(list1Node1)
	if printList(newList1) != "[[7,null],[13,0],[11,4],[10,2],[1,0]]" {
		panic("")
	}

	list2Node1 := &Node{3, nil, nil}
	list2Node2 := &Node{3, nil, nil}
	list2Node3 := &Node{3, nil, nil}
	list2Node1.Next = list2Node2
	list2Node2.Next = list2Node3
	list2Node2.Random = list2Node1
	newList2 := copyRandomList(list2Node1)
	if printList(newList2) != "[[3,null],[3,0],[3,null]]" {
		panic("")
	}
}
