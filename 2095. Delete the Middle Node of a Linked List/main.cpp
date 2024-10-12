#include <iostream>

//2095. Delete the Middle Node of a Linked List
//You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteMiddle(ListNode* head){
    if(head == nullptr || head->next == nullptr)
        return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    while(fast!=nullptr && fast->next!=nullptr){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    delete slow;
    slow = nullptr;
    return head;
}
int main(int argc, const char * argv[]) {
    ListNode* list = new ListNode(2,new ListNode(1));
    ListNode* newList = deleteMiddle(list);
    ListNode* curr = newList;
    while(curr!=nullptr){
        std::cout<<curr->val<<" ";
        curr = curr->next;
    }
   
}
