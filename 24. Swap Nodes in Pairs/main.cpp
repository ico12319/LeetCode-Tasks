#include <iostream>

//24. Swap Nodes in Pairs
//Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)


struct ListNode{
    
    int val;
    ListNode* next;
    
    ListNode(int val,ListNode* next) : val(val),next(next){}
    ListNode(int val) : val(val),next(nullptr){}
    
};


ListNode* swapNodes(ListNode* head){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    
    while(prev && prev->next && prev->next->next){
        ListNode* first = prev->next;
        ListNode* secnd = first->next;
        first->next = secnd->next;
        secnd->next = first;
        prev->next = secnd;
        prev = first;
    }
    ListNode* res = dummy->next;
    return res;
}

int main(int argc, const char * argv[]) {
    ListNode* list = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4))));
    ListNode* swapped = swapNodes(list);
    ListNode* curr = swapped;
    while(curr){
        std::cout<<curr->val<<" ";
        curr = curr->next;
    }
}
