#include <iostream>
#include <unordered_set>

//817. Linked List Components
//You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.

struct node{
    int val;
    node* next;
    
    node(int val) : val(val),next(nullptr){}
};

void destroy(node* head){
    if(!head)
        return;
    node* curr = head;
    while(curr){
        node* to_delete = curr;
        curr = curr->next;
        delete to_delete;
    }
}

int num_components(node* head,std::vector<int>& nums){
    std::unordered_set<int> in_nums(nums.begin(),nums.end());
    node* curr = head;
    std::unordered_map<int, bool> participate;
    int connected_components = 0;
    while(curr){
        if(in_nums.contains(curr->val) && !participate[curr->val]){
            connected_components++;
            participate[curr->val] = true;
            while(curr->next && in_nums.contains(curr->next->val)){
                participate[curr->next->val] = true;
                curr = curr->next;
            }
        }
        curr = curr->next;
    }
    return connected_components;
}


int main(int argc, const char * argv[]) {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(0);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(3);
    std::vector<int> nums = {3,4,0,2,1};
    std::cout<<num_components(head, nums)<<std::endl;
    destroy(head);
}
