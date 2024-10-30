#include <iostream>

//1721. Swapping Nodes in a Linked List
//You are given the head of a linked list, and an integer k.Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).


struct ListNode{
    
    int val;
    ListNode* next;
    
    ListNode(int val,ListNode* next) : val(val),next(next){}
    ListNode(int val) : val(val),next(nullptr){}
};


ListNode* swapNodes(ListNode* head,int k){
    ListNode* curr = head;
    ListNode* first = head;
    ListNode* second = head;
    
    for(int i = 1;i<k;i++)
        first = first->next;
    
    for(int i = 0;i<k;i++)
        curr = curr->next;
    
    while(curr){
        curr = curr->next;
        second = second->next;
    }
    
    int tempValue = first->val;
    first->val = second->val;
    second->val = tempValue;
    
    return head;
}

int main() {
   
    ListNode* list = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    ListNode* swapped = swapNodes(list, 2);
    ListNode* cur = swapped;
    while(cur){
        std::cout<<cur->val<<" ";
        cur = cur->next;
    }
    
}
