package main

import "fmt"

//1530. Number of Good Leaf Nodes Pairs
//You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.
//Return the number of good leaf node pairs in the tree.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func NewNode(val int) *TreeNode {
	return &TreeNode{Val: val, Left: nil, Right: nil}
}

func convert(root *TreeNode, adj map[*TreeNode][]*TreeNode, leaves *[]*TreeNode) {
	if root == nil {
		return
	}
	if root.Left != nil {
		adj[root] = append(adj[root], root.Left)
		adj[root.Left] = append(adj[root.Left], root)
	}
	if root.Right != nil {
		adj[root] = append(adj[root], root.Right)
		adj[root.Right] = append(adj[root.Right], root)
	}
	if root.Right == nil && root.Left == nil {
		*leaves = append(*leaves, root)
	}
	convert(root.Left, adj, leaves)
	convert(root.Right, adj, leaves)
}

func dfs(adj map[*TreeNode][]*TreeNode, visited map[*TreeNode]bool, start *TreeNode, elements *int, steps int, target int, visited2 map[*TreeNode]bool) {
	if !visited[start] {
		visited[start] = true
		steps++
		if steps > target {
			return
		}
		if steps <= target && start.Left == nil && start.Right == nil {
			*elements++
		}
		for _, child := range adj[start] {
			if !visited[child] && !visited2[child] {
				dfs(adj, visited, child, elements, steps, target, visited2)
			}
		}
	}

}

func countPairs(root *TreeNode, distance int) int {
	adj := make(map[*TreeNode][]*TreeNode)
	leaves := make([]*TreeNode, 0)
	pairs := 0
	convert(root, adj, &leaves)
	globalVisited := make(map[*TreeNode]bool)

	for _, leaf := range leaves {
		steps := -1
		visited := make(map[*TreeNode]bool)
		dfs(adj, visited, leaf, &pairs, steps, distance, globalVisited)
		globalVisited[leaf] = true
	}
	return pairs - len(leaves)
}

func main() {
	root := NewNode(1)
	root.Left = NewNode(2)
	root.Right = NewNode(3)
	root.Left.Right = NewNode(4)
	//root.Left.Right = NewNode(5)
	//root.Right.Left = NewNode(6)
	//root.Right.Right = NewNode(7)

	fmt.Println(countPairs(root, 3))
}
