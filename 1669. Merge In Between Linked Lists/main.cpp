#include <iostream>

//1669. Merge In Between Linked Lists
//You are given two linked lists: list1 and list2 of sizes n and m respectively.Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int val,ListNode* next) : val(val),next(next){}
    ListNode(int val) : val(val),next(nullptr){}
};


ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* prev = nullptr;
    ListNode* curr = list1;
    
    for(int i = 0;i<a;i++){
        prev = curr;
        curr = curr->next;
    }
    
    for(int i = a;i<b;i++)
        curr = curr->next;
   
    ListNode* next = curr->next;
    prev->next = list2;
    while(list2 && list2->next)
        list2 = list2->next;
    
    list2->next = next;
    return list1;
}

int main() {
    ListNode* list1 = new ListNode(10,new ListNode(1,new ListNode(13,new ListNode(6,new ListNode(9,new ListNode(5))))));
    ListNode* list2 = new ListNode(101,new ListNode(102,new ListNode(103)));
    
    ListNode* merged = mergeInBetween(list1, 3,4, list2);
    while(merged){
        std::cout<<merged->val<<" ";
        merged = merged->next;
    }
}
