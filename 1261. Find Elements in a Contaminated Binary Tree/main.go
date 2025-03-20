package main

import "fmt"

//1261. Find Elements in a Contaminated Binary Tree
//Given a binary tree with the following rules:
//root.val == 0
//For any treeNode:
//If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
//If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
//Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.
//Implement the FindElements class:
//FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
//bool find(int target) Returns true if the target value exists in the recovered binary tree.

type node struct {
	val   int
	left  *node
	right *node
}

func newNode(val int) *node {
	return &node{val: val}
}

type FindElements struct {
	containedValues map[int]int
}

func recover(root *node, isRoot *bool, contained map[int]int) {
	if root == nil {
		return
	}
	if *isRoot {
		root.val = 0
		*isRoot = false
	}
	contained[root.val]++
	if root.left != nil {
		root.left.val = 2*root.val + 1
	}
	if root.right != nil {
		root.right.val = 2*root.val + 2
	}
	recover(root.left, isRoot, contained)
	recover(root.right, isRoot, contained)
}

func Constructor(root *node) FindElements {
	containedValues := make(map[int]int)
	isRoot := true
	recover(root, &isRoot, containedValues)
	return FindElements{containedValues: containedValues}
}

func (this *FindElements) Find(target int) bool {
	_, contained := this.containedValues[target]
	return contained
}

func main() {
	root := newNode(-1)
	root.left = newNode(-1)
	root.right = newNode(-1)
	root.left.left = newNode(-1)
	root.left.right = newNode(-1)

	finder := Constructor(root)
	fmt.Println(finder.Find(4))
}
