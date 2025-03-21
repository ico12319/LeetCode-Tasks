package main

import (
	"container/list"
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func NewNode(val int) *TreeNode {
	return &TreeNode{Val: val, Left: nil, Right: nil}
}

type Pair struct {
	child  *TreeNode
	parent *TreeNode
}

func bfs(root *TreeNode, levels *int) []map[int]*TreeNode {
	result := make([]map[int]*TreeNode, 0, 8)
	rootMap := map[int]*TreeNode{root.Val: nil}
	result = append(result, rootMap)
	*levels++

	q := list.New()
	if root.Left != nil {
		q.PushBack(Pair{root.Left, root})
	}
	if root.Right != nil {
		q.PushBack(Pair{root.Right, root})
	}

	for q.Len() != 0 {
		currLevelSize := q.Len()
		currLevel := make(map[int]*TreeNode)
		for i := 0; i < currLevelSize; i++ {
			pairItem := q.Front().Value.(Pair)
			q.Remove(q.Front())
			currLevel[pairItem.child.Val] = pairItem.parent

			if pairItem.child.Left != nil {
				q.PushBack(Pair{pairItem.child.Left, pairItem.child})
			}
			if pairItem.child.Right != nil {
				q.PushBack(Pair{pairItem.child.Right, pairItem.child})
			}
		}
		result = append(result, currLevel)
		*levels++
	}
	return result
}

func nodesCount(root *TreeNode, count *int) {
	if root == nil {
		return
	}
	*count++
	nodesCount(root.Left, count)
	nodesCount(root.Right, count)
}

func flipEquiv(root1 *TreeNode, root2 *TreeNode) bool {
	if root1 == nil && root2 == nil {
		return true
	}
	count1 := 0
	count2 := 0
	nodesCount(root1, &count1)
	nodesCount(root2, &count2)
	if count1 != count2 {
		return false
	}
	levels := 0
	firstTreeLevelTraversed := bfs(root1, &levels)
	q := list.New()
	currLevel := 0
	q.PushBack(Pair{root2, nil})

	for q.Len() != 0 {
		currLevelSize := q.Len()
		for i := 0; i < currLevelSize; i++ {
			currNode := q.Front().Value.(Pair)
			q.Remove(q.Front())
			if currLevel >= len(firstTreeLevelTraversed) {
				return false
			}
			parent, contained := firstTreeLevelTraversed[currLevel][currNode.child.Val]
			if !contained {
				return false
			} else if currNode.parent == nil && parent == nil {

			} else if !contained || (parent != nil && currNode.parent == nil) || (parent == nil && currNode.parent != nil) || (parent.Val != currNode.parent.Val) {
				return false
			}

			if currNode.child.Left != nil {
				q.PushBack(Pair{currNode.child.Left, currNode.child})
			}
			if currNode.child.Right != nil {
				q.PushBack(Pair{currNode.child.Right, currNode.child})
			}
		}
		currLevel++
	}
	return true

}

func main() {

	root1 := NewNode(1)
	root1.Left = NewNode(2)
	root1.Left.Left = NewNode(4)
	root1.Left.Right = NewNode(5)
	root1.Left.Right.Left = NewNode(7)
	root1.Left.Right.Right = NewNode(8)
	root1.Right = NewNode(3)
	root1.Right.Left = NewNode(6)

	root2 := NewNode(1)
	root2.Left = NewNode(3)
	root2.Left.Right = NewNode(6)
	root2.Right = NewNode(2)
	root2.Right.Left = NewNode(4)
	root2.Right.Right = NewNode(5)
	root2.Right.Right.Left = NewNode(8)
	root2.Right.Right.Right = NewNode(7)

	fmt.Println(flipEquiv(root1, root2))
}
