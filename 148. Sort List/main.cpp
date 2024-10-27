#include <iostream>

//148. Sort List
//Given the head of a linked list, return the list after sorting it in ascending order.

struct ListNode{
    ListNode* next;
    int val;
    
    ListNode(int val) : val(val),next(nullptr){}
    ListNode(int val,ListNode* next) : val(val), next(next){}
};


ListNode* getMid(ListNode* head){
    if(head == nullptr)
        return nullptr;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* list1,ListNode* list2){
    ListNode* dummy = new ListNode(0);//dummy
    ListNode* curr = dummy;
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
    ListNode* res = dummy->next;
    delete dummy;
    return res;
        
}

ListNode* mergeSort(ListNode* list){
    if(list == nullptr || list->next == nullptr)
        return list;
    
    ListNode* middle = getMid(list);
    
    ListNode* left = list;
    ListNode* right = middle->next;
    middle->next = nullptr;
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

int main(int argc, const char * argv[]) {
    
    ListNode* list = new ListNode(4,new ListNode(2,new ListNode(1,new ListNode(3))));
    ListNode* sorted = mergeSort(list);
    while(sorted!=nullptr){
        std::cout<<sorted->val<<" ";
        sorted = sorted->next;
    }
    delete list;
    
}
