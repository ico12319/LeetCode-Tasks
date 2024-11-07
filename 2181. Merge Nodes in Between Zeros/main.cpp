#include <iostream>

//2181. Merge Nodes in Between Zeros
//You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int val) : val(val),next(nullptr){}
    ListNode(int val,ListNode* next) : val(val),next(next){}
};


ListNode* mergeNodes(ListNode* head){
    ListNode* dummy = new ListNode(0);
    ListNode* iter = dummy;
    ListNode* curr = head->next;
    int sum = 0;
    while(curr){
        if(curr->val == 0){
            iter->next = new ListNode(sum);
            iter = iter->next;
            sum = 0;
        }
        sum+=curr->val;
        curr = curr->next;
    }
    ListNode* toReturn = dummy->next;
    delete dummy;
    return toReturn;
}

int main(int argc, const char * argv[]) {
    ListNode* list = new ListNode(0,new ListNode(3,new ListNode(1,new ListNode(0,new ListNode(4,new ListNode(5,new ListNode(2,new ListNode(0))))))));
    ListNode* newList = mergeNodes(list);
    
    ListNode* curr = newList;
    while(curr){
        std::cout<<curr->val<<" ";
        curr = curr->next;
    }
}
