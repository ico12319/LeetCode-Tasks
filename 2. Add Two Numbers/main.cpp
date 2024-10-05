#include <stdio.h>
#include <iostream>

//2. Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    
    int carry = 0;
    while(l1!=nullptr || l2!=nullptr || carry){
        int sum = carry;
        if(l1!=nullptr){
            sum+=l1->val;
            l1 = l1->next;
        }
        if(l2!=nullptr){
            sum+=l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }
    return dummy->next;
}

int main(){
    ListNode* list1 = new ListNode(2,new ListNode(4,new ListNode(3)));
    ListNode* list2 = new ListNode(5,new ListNode(6,new ListNode(4)));
    ListNode* res = addTwoNumbers(list1, list2);
    ListNode* curr = res;
    while(curr!=nullptr){
        std::cout<<curr->val<<" ";
        curr = curr->next;
    }
    delete res;
    delete list1;
    delete list2;
}
