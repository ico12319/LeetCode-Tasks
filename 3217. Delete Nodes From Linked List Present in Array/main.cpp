#include <iostream>
#include <unordered_set>

//3217. Delete Nodes From Linked List Present in Array
//You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int val) : val(val),next(nullptr){}
    ListNode(int val,ListNode* next) : val(val),next(next){}
};

std::unordered_set<int> fillSeenNumbers(const std::vector<int>& nums){
    std::unordered_set<int> seen;
    for(const auto& num : nums)
        seen.insert(num);
    
    return seen;
}


ListNode* modifiedList(const std::vector<int>& nums, ListNode* head) {
    std::unordered_set<int> seen = fillSeenNumbers(nums);
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* curr = dummy;
    while(curr && curr->next){
        if(seen.contains(curr->next->val)){
            ListNode* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
        }
        else
            curr = curr->next;
    }
    ListNode* toReturn = dummy->next;
    delete dummy;
    return toReturn;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,2,3};
    ListNode* list = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    ListNode* modified = modifiedList(nums, list);
    ListNode* curr = modified;
    while(curr){
        std::cout<<curr->val<<" ";
        curr = curr->next;
    }
    
}
