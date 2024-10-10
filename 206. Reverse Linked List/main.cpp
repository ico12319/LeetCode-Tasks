#include <iostream>
#include <stack>

//206. Reverse Linked List
//Given the head of a singly linked list, reverse the list, and return the reversed list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    
 };


ListNode* reverseList(ListNode* head){
    ListNode* temp = head;
    std::stack<int> res;
    while(temp!=nullptr){
        res.push(temp->val);
        temp = temp->next;
    }
    
    temp = head;
    while(temp!=nullptr){
        temp->val = res.top();
        res.pop();
        temp = temp->next;
    }
    return head;
}

void print(ListNode* list){
    ListNode* curr = list;
    while(curr!=nullptr){
        std::cout<<curr->val<<" ";
        curr = curr->next;
    }
}
int main(int argc, const char * argv[]) {
    ListNode* list =  new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    ListNode* reversed = reverseList(list);
    print(reversed);
}
