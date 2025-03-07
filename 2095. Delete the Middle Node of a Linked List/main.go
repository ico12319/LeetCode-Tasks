package main

import "fmt"

//2095. Delete the Middle Node of a Linked List
//You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
//The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

type ListNode struct {
	Val  int
	Next *ListNode
}

func newListNode(val int) *ListNode {
	return &ListNode{Val: val, Next: nil}
}

func deleteMiddle(head *ListNode) *ListNode {
	var slow **ListNode = &head
	var fast **ListNode = &head
	for *fast != nil && (*fast).Next != nil {
		fast = &((*fast).Next.Next)
		slow = &((*slow).Next)
	}
	*slow = (*slow).Next
	return head
}

func printList(head *ListNode) {
	curr := head
	for curr != nil {
		fmt.Printf("%v ", curr.Val)
		curr = curr.Next
	}
}

func main() {
	head := newListNode(1)
	head.Next = newListNode(2)
	head.Next.Next = newListNode(3)
	head.Next.Next.Next = newListNode(4)
	head.Next.Next.Next.Next = newListNode(5)

	head = deleteMiddle(head)
	printList(head)
}
