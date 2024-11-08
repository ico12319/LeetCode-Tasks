#include <iostream>

//2487. Remove Nodes From Linked List
//You are given the head of a linked list.Remove every node which has a node with a greater value anywhere to the right side of it.Return the head of the modified linked list.


struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int val,ListNode* next) : val(val),next(next){}
    ListNode(int val) : val(val),next(nullptr){}
};


ListNode* reverse(ListNode* head){
    ListNode* next = nullptr;
    ListNode* prev = nullptr;
    
    while(head){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return prev;
}


ListNode* removeNodes(ListNode* head){
    ListNode* reversed = reverse(head);
    ListNode* curr = reversed;
    ListNode* prev = nullptr;
    int currMax = curr->val;
    while(curr){
        if(currMax <= curr->val){
            currMax = curr->val;
            prev = curr;
            curr = curr->next;
        }
        else{
            ListNode* toDelete = curr;
            curr = curr->next;
            if(prev)
                prev->next = curr;
            delete toDelete;
        }
    }
    return reverse(reversed);
}

int main(int argc, const char * argv[]) {
    ListNode* list = new ListNode(5,new ListNode(2,new ListNode(13,new ListNode(3,new ListNode(8)))));
    ListNode* rev = removeNodes(list);
    while(rev){
        std::cout<<rev->val<<" ";
        rev = rev->next;
    }
}
