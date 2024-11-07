#include <iostream>

//160. Intersection of Two Linked Lists
//Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int val) : val(val),next(nullptr){}
    ListNode(int val,ListNode* next) : val(val),next(next){}
};

int getSize(ListNode* head){
    ListNode* curr = head;
    int size = 0;
    while(curr){
        size++;
        curr = curr->next;
    }
    return size;
}

ListNode* getIntersectionNode(ListNode* headA,ListNode* headB){
    ListNode* currA = headA;
    ListNode* currB = headB;
    
    int sizeA = getSize(currA);
    int sizeB = getSize(currB);
    
    int diff = std::abs(sizeA - sizeB);
    if(sizeA > sizeB){
        while(diff != 0 && currA){
            currA = currA->next;
            diff--;
        }
    }
    else if(sizeA < sizeB){
        while(diff != 0 && currB){
            currB = currB->next;
            diff--;
        }
    }
    
    while(currA && currB){
        if(currA == currB)
            return currA;
        
        currA = currA->next;
        currB = currB->next;
    }
    return nullptr;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
