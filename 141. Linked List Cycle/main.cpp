#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int val,ListNode* next) : val(val),next(next){}
    ListNode(int val) : val(val),next(nullptr){}
};


bool hasCycle(ListNode* head){
    ListNode* first = head;
    ListNode* second = head;
    
    while(first && first->next){
        first = first->next->next;
        second = second->next;
        if(first == second)
            return true;
    }
    return false;
}


int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    
    std::cout<<hasCycle(head)<<std::endl;
}
