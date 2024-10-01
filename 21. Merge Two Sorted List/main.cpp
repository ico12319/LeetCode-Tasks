#include <iostream>

//21. Merge Two Sorted Lists
//You are given the heads of two sorted linked lists list1 and list2.Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.Return the head of the merged linked list.

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeSortedList(ListNode* list1,ListNode* list2){
    if(list1 == nullptr)
        return list2;
    if(list2 == nullptr)
        return list1;
    ListNode* head;
    if(list1->val <= list2->val){
        head = list1;
        list1 = list1->next;
    }
    else{
        head = list2;
        list2 = list2->next;
    }
    
    ListNode* curr = head;
    while(list1!=nullptr && list2!=nullptr){
        if(list1->val <= list2->val){
            curr->next = list1;
            list1 = list1->next;
        }
        else{
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    if(list1!=nullptr)
        curr->next = list1;
    if(list2!=nullptr)
        curr->next = list2;
    return head;
        
}

void print(ListNode* head){
    ListNode* curr = head;
    while(curr!=nullptr){
        if(curr->next != nullptr)
            std::cout<<curr->val<<"->";
        else
            std::cout<<curr->val<<" ";
        curr = curr->next;
    }
}

int main(int argc, const char * argv[]) {
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    
    ListNode* l3 = mergeSortedList(l1, l2);
    print(l3);
    delete l3;
    l1 = l2 = l3 = nullptr;

}
