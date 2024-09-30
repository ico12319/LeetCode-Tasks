#include <iostream>

//83. Remove Duplicates from Sorted List
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once.Return the linked list sorted as well.

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* deleteDuplicates(ListNode* head){
    if(head == nullptr)
        return head;
    
    ListNode* curr = head;
    while(curr!=nullptr && curr->next!=nullptr){
        if(curr->val == curr->next->val){
            ListNode* next = curr->next->next;
            delete curr->next;
            curr->next = next;
        }
        else
            curr = curr->next;
    }
    return head;
}

void printList(ListNode* head){
    ListNode* curr = head;
    while(curr != nullptr){
        if(curr->next != nullptr)
            std::cout<<curr->val<<"->";
        else
            std::cout<<curr->val<<" ";
        curr = curr->next;
    }
}

int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(1,new ListNode(1,new ListNode(2)));
    ListNode* newHead = deleteDuplicates(head);
    printList(newHead);
    delete head;
}
