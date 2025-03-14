package main

import (
	"container/list"
	"fmt"
)

//143. Reorder List

type node struct {
	val  int
	next *node
}

func newNode(val int) *node {
	return &node{val: val}
}

func findMid(head *node) *node {
	fast := head
	slow := head
	for fast != nil && fast.next != nil {
		slow = slow.next
		fast = fast.next.next
	}
	return slow
}

func reverse(head *node) *list.List {
	stack := list.New()
	curr := head
	for curr != nil {
		stack.PushFront(curr)
		curr = curr.next
	}
	return stack
}

func reorder(head *node) *node {
	stack := reverse(head)
	mid := findMid(head)
	curr := head
	for {
		next := curr.next
		newNext := stack.Front().Value.(*node)
		if newNext == mid {
			break
		}
		curr.next = newNext
		newNext.next = next
		stack.Remove(stack.Front())
		curr = next
	}
	curr.next = mid
	curr = curr.next
	if curr != nil {
		curr.next = nil
	}
	return head
}

func main() {

	head := newNode(1)
	head.next = newNode(2)
	head.next.next = newNode(3)
	head.next.next.next = newNode(4)
	head.next.next.next.next = newNode(5)

	head = reorder(head)

	for head != nil {
		fmt.Printf("%d ", head.val)
		head = head.next
	}
}
