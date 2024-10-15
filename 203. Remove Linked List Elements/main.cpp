#include <iostream>
#include <unordered_set>

//203. Remove Linked List Elements
//Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode* removeElements(ListNode* head,int val){
    ListNode* temp = new ListNode(0);
    temp->next = head;
    ListNode* curr = temp;
    while(curr->next!=nullptr){
        if(curr->next->val == val)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }
    return temp->next;
}

int main(int argc, const char * argv[]) {
    ListNode* list = new ListNode(1,new ListNode(2,new ListNode(6,new ListNode(3,new ListNode(4,new ListNode(5,new ListNode(6)))))));
    ListNode* removed = removeElements(list, 6);
}
