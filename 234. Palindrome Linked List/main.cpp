#include <iostream>
#include <stack>

//234. Palindrome Linked List
//Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


bool isPalindrome(ListNode* head){
    std::stack<int> values;
    ListNode* curr = head;
    while(curr!=nullptr){
        values.push(curr->val);
        curr = curr->next;
    }
    curr = head;
    while(curr != nullptr && curr->val == values.top()){
        values.pop();
        curr = curr->next;
    }
    return curr == nullptr;
}


int main(int argc, const char * argv[]) {
    
    ListNode* list = new ListNode(1,new ListNode(2,new ListNode(2,new ListNode(1))));
    std::cout<<isPalindrome(list)<<std::endl;
}
