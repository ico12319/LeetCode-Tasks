package main

import (
	"container/list"
	"fmt"
)

//919. Complete Binary Tree Inserter
//A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.
//Design an algorithm to insert a new node to a complete binary tree keeping it complete after the insertion.
type node struct {
	Val   int
	Left  *node
	Right *node
}

func newNode(val int) *node {
	return &node{Val: val, Left: nil, Right: nil}
}

type CBTInserter struct {
	nodes     []*node
	lastIndex int
}

func Constructor(root *node) CBTInserter {
	var inserter CBTInserter
	inserter.nodes = make([]*node, 0, 8)
	inserter.lastIndex = 0
	q := list.New()
	q.PushBack(root)
	for q.Len() != 0 {
		currLevelSize := q.Len()
		for i := 0; i < currLevelSize; i++ {
			curr := q.Front().Value.(*node)
			inserter.nodes = append(inserter.nodes, curr)
			q.Remove(q.Front())
			if curr.Left != nil {
				q.PushBack(curr.Left)
				inserter.nodes[inserter.lastIndex].Left = curr.Left
			}
			if curr.Right != nil {
				q.PushBack(curr.Right)
				inserter.nodes[inserter.lastIndex].Right = curr.Right
			}
			inserter.lastIndex++
		}
	}
	return inserter
}

func (this *CBTInserter) insert(val int) int {
	index := this.lastIndex
	toAdd := newNode(val)
	parent := this.nodes[(index-1)/2]
	if index%2 == 0 {
		parent.Right = toAdd
	} else {
		parent.Left = toAdd
	}
	this.lastIndex++
	this.nodes = append(this.nodes, toAdd)
	return parent.Val
}

func (this *CBTInserter) GetRoot() *node {
	return this.nodes[0]
}

func in_order(root *node) {
	if root == nil {
		return
	}
	in_order(root.Left)
	fmt.Printf("%v ", root.Val)
	in_order(root.Right)
}

func main() {
	root := newNode(1)
	root.Left = newNode(2)

	inserter := Constructor(root)
	fmt.Println(inserter.insert(3))
	fmt.Println(inserter.insert(4))

	in_order(inserter.GetRoot())

}
