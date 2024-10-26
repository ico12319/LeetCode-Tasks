#include <iostream>

//86. Partition List
//Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.You should preserve the original relative order of the nodes in each of the two partitions.

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* partition(ListNode* head,int x){
    ListNode* lessHead = new ListNode(0);
    ListNode* greatHead = new ListNode(0);
    ListNode* currLess = lessHead;
    ListNode* currGreat = greatHead;
    ListNode* curr = head;
    
    while(curr!=nullptr){
        if(curr->val < x){
            currLess->next = curr;
            currLess = currLess->next;
        }
        else{
            currGreat->next = curr;
            currGreat = currGreat->next;
        }
        curr = curr->next;
    }
    
    currGreat->next = nullptr;
    currLess->next = greatHead->next;
    
    ListNode* res = lessHead->next;
    delete lessHead;
    delete greatHead;
    
    return res;
}

int main(int argc, const char * argv[]) {
    
    ListNode* list = new ListNode(1,new ListNode(4,new ListNode(3,new ListNode(2,new ListNode(5, new ListNode(2))))));
    ListNode* head = partition(list, 3);
    ListNode* curr = head;
    while(curr!=nullptr){
        std::cout<<curr->val<<" ";
        curr = curr->next;
    }
    
    delete list;
}
