#include <iostream>

//82. Remove Duplicates from Sorted List II
//Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int val) : val(val),next(nullptr){}
    ListNode(int val,ListNode* next) : val(val),next(next){}
};

ListNode* deleteDuplicates(ListNode* head){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;
    while(curr){
        bool isFound = false;
        while(curr->next && curr->val == curr->next->val){
            isFound = true;
            curr = curr->next;
        }
        if(isFound)
            prev->next = curr->next;
        else
            prev = prev->next;
        curr = curr->next;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
}

int main(int argc, const char * argv[]) {
    ListNode* list = new ListNode(1,new ListNode(2,new ListNode(2,new ListNode(2,new ListNode(3)))));
    ListNode* curr = deleteDuplicates(list);
    while(curr){
        std::cout<<curr->val<<" ";
        curr = curr->next;
    }
    delete list;
}
