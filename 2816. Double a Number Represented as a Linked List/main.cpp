#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseLinkedList(ListNode* head){
    ListNode* curr = head;
    std::stack<int> values;
    while(curr!=nullptr){
        values.push(curr->val);
        curr = curr->next;
    }
    curr = head;
    while(!values.empty()){
        curr->val = values.top();
        values.pop();
        curr = curr->next;
    }
    return head;
}

ListNode* doubleIt(ListNode* head){
    int carry = 0;
    head = reverseLinkedList(head);
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    while(head!=nullptr){
        int currValue = carry + 2 * head->val;
        carry = currValue / 10;
        curr->next = new ListNode(currValue % 10);
        curr = curr->next;
        head = head ->next;
    }
    if(carry > 0)
        curr->next = new ListNode(carry);
    return reverseLinkedList(dummy->next);
}

int main(int argc, const char * argv[]) {
    ListNode* list = new ListNode(9,new ListNode(9,new ListNode(9)));
    ListNode* newList = doubleIt(list);
    ListNode* curr = newList;
    
    delete list;
    delete newList;
}
