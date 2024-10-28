#include <iostream>
#include <stack>

//2130. Maximum Twin Sum of a Linked List
//In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.
//Given the head of a linked list with even length, return the maximum twin sum of the linked list.

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int val) : val(val),next(nullptr){}
    ListNode(int val,ListNode* next) : val(val),next(next){}
};


ListNode* getMid(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    std::stack<int> elements;
    while(curr){
        elements.push(curr->val);
        curr = curr->next;
    }
    
    curr = head;
    while(!elements.empty()){
        curr->val = elements.top();
        elements.pop();
        curr = curr->next;
    }
    return head;
}

int pairSum(ListNode* head){
    
    ListNode* mid = getMid(head);
    ListNode* secondHalf = reverse(mid);
    
    
    
    ListNode* left = head;
    ListNode* right = secondHalf;
    int maxSum = INT_MIN;
    while(right){
        int currSum = left->val + right->val;
        maxSum = std::max(currSum, maxSum);
        left = left->next;
        right = right->next;
    }
    return maxSum;
}

int main(int argc, const char * argv[]) {
    
    ListNode* list = new ListNode(1,new ListNode(1000));
}
