package main

import (
	"fmt"
	"math"
)

//1448. Count Good Nodes in Binary Tree
//Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
//Return the number of good nodes in the binary tree.
type node struct {
	val   int
	left  *node
	right *node
}

func newNode(val int) *node {
	return &node{val: val}
}

func getGoodNodesCount(root *node, count *int, max int) {
	if root == nil {
		return
	}
	if root.val > max {
		max = root.val
	}
	if max <= root.val {
		*count++
	}
	getGoodNodesCount(root.left, count, max)
	getGoodNodesCount(root.right, count, max)
}

func goodNodes(root *node) int {
	count := 0
	maximal := math.MinInt32
	getGoodNodesCount(root, &count, maximal)
	return count
}

func main() {

	root := newNode(3)
	root.left = newNode(1)
	root.right = newNode(4)
	root.left.left = newNode(3)
	root.right.left = newNode(1)
	root.right.right = newNode(5)

	fmt.Println(goodNodes(root))
}
