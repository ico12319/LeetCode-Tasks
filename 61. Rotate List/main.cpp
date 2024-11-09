#include <iostream>

//61. Rotate List
//Given the head of a linked list, rotate the list to the right by k places.

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int val,ListNode* next) : val(val),next(next){}
    ListNode(int val) : val(val),next(nullptr){}
};


ListNode* pop_back(ListNode*& head, ListNode*& tail){
    if(!head)
        return nullptr;
    
    if(!head->next){
        ListNode* last = head;
        head = tail = nullptr;
        return last;
    }
    
    ListNode* curr = head;
    
    while(curr && curr->next != tail)
        curr = curr->next;

    
    ListNode* last = tail;
    //delete tail;
    tail = curr;
    tail->next = nullptr;
    
    return last;
}

void push_front(ListNode*& head,ListNode*& tail,ListNode* toAdd){
    if(head == nullptr)
        head = tail = toAdd;
    else{
        toAdd->next = head;
        head = toAdd;
    }
}


ListNode* rotateRight(ListNode* head,int k){
    ListNode* curr = head;
    int size = 1;
    while(curr && curr->next){
        curr = curr->next;
        size++;
    }
    k %= size;
    if(k == 0)
        return head;
    
    ListNode* tail = curr;
    
    for(int i = 0;i<k;i++){
        ListNode* last = pop_back(head, tail);
        push_front(head, tail, last);
    }
    return head;
    
}


int main(int argc, const char * argv[]) {
  
    ListNode* list = new ListNode(0,new ListNode(1,new ListNode(3,new ListNode(4,new ListNode(2)))));
    ListNode* curr = rotateRight(list, 2);
    while(curr){
        std::cout<<curr->val<<" ";
        curr = curr->next;
    }
    //std::cout<<curr->val<<std::endl;
    
}
