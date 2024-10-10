#include <iostream>

//876. Middle of the Linked List
//Given the head of a singly linked list, return the middle node of the linked list.If there are two middle nodes, return the second middle node.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode* middleNode(ListNode* head){
    ListNode* slowPointer = head;
    ListNode* fastPointer = head;
    while(fastPointer!=nullptr && fastPointer->next != nullptr){
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }
    return slowPointer;
}

int main(int argc, const char * argv[]) {
    ListNode* list =  new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    ListNode* midEl = middleNode(list);
    std::cout<<midEl->val<<std::endl;
}
