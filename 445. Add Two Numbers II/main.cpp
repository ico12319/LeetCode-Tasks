#include <iostream>

//445. Add Two Numbers II
//You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.You may assume the two numbers do not contain any leading zero, except the number 0 itself.

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int val,ListNode* next) : val(val),next(next){}
    ListNode(int val) : val(val),next(nullptr){}
};

ListNode* reverse(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    
    while(head){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return prev;
}

ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
    if(!l1 && !l2) return nullptr;
    if(!l1) return l2;
    if(!l2) return l1;

    ListNode* rev1 = reverse(l1);
    ListNode* rev2 = reverse(l2);
    ListNode* res = new ListNode(0);
    ListNode* iter = res;
    int carry = 0;
    while(rev1 && rev2){
        int currSum = rev1->val + rev2->val + carry;
        iter->next = new ListNode(currSum % 10);
        carry = currSum / 10;
        iter = iter->next;
        rev1 = rev1->next;
        rev2 = rev2->next;
    }
        
    while(rev1){
        int currSum = rev1->val + carry;
        iter->next = new ListNode(currSum % 10);
        carry = currSum / 10;
        iter = iter->next;
        rev1 = rev1->next;
    }
    while(rev2){
        int currSum = rev2->val + carry;
        iter->next = new ListNode(currSum % 10);
        carry = currSum / 10;
        iter = iter->next;
        rev2 =rev2->next;
    }
    
    if(carry)
        iter->next = new ListNode(carry);
    
    ListNode* toReturn  = res->next;
    delete res;
    return reverse(toReturn);
}

int main(int argc, const char * argv[]) {
    ListNode* l1 = new ListNode(9,new ListNode(9));
    ListNode* l2 = new ListNode(1);
    ListNode* res = addTwoNumbers(l1, l2);
    while(res){
        std::cout<<res->val<<" ";
        res = res->next;
    }
}
