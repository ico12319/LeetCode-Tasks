#include <iostream>

//328. Odd Even Linked List
//Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.The first node is considered odd, and the second node is even, and so on.Note that the relative order inside both the even and odd groups should remain as it was in the input.

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int val,ListNode* next) : val(val),next(next){}
    ListNode(int val) : val(val),next(nullptr){}
};


bool isEven(int num){
    return !(num & 1);
}

ListNode* oddEvenListDummy(ListNode* head){ // dummy solution
    ListNode* odds = new ListNode(0);
    ListNode* evens = new ListNode(0);
    ListNode* oddIter = odds;
    ListNode* evenIter = evens;
    ListNode* curr = head;
    
    int ind = 1;
    while(curr){
        if(!isEven(ind)){
            oddIter->next = new ListNode(curr->val);
            oddIter = oddIter->next;
        }
        else{
            evenIter->next = new ListNode(curr->val);
            evenIter = evenIter->next;
        }
        curr = curr->next;
        ind++;
    }
    oddIter->next = evens->next;
    ListNode* toReturn = odds->next;
    delete odds;
    delete evens;
    return toReturn;
}

ListNode* oddEvenList(ListNode* head){
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;
    
    while(even && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main(int argc, const char * argv[]) {
    ListNode* list = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    ListNode* oddEven = oddEvenList(list);
    ListNode* curr = oddEven;
    while(curr){
        std::cout<<curr->val<<" ";
        curr = curr->next;
    }
}
