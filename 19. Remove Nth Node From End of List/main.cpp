#include <iostream>

//19. Remove Nth Node From End of List
//Given the head of a linked list, remove the nth node from the end of the list and return its head.

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int val,ListNode* next) : val(val), next(next){}
};

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;
    
    for(int i = 0;i<=n;i++)
        first = first->next;
    
    while(first){
        second = second->next;
        first = first->next;
    }
    
    ListNode* toDelete = second->next;
    second->next = second->next->next;
    delete toDelete;
    return dummy->next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* list = new ListNode(1,new ListNode(2,new ListNode(5)));
    ListNode* removed = removeNthFromEnd(list, 1);
    printList(removed);
}

