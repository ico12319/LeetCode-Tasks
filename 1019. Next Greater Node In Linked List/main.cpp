#include <iostream>
#include <stack>

//1019. Next Greater Node In Linked List
//You are given the head of a linked list with n nodes.For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.



struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int val,ListNode* next) : val(val),next(next){}
    ListNode(int val) : val(val),next(nullptr){}
};


std::vector<int> fill(ListNode* head){
    std::vector<int> res;
    ListNode* curr = head;
    while(curr){
        res.push_back(curr->val);
        curr = curr->next;
    }
    return res;
}

std::vector<int> nextLargerNodes(ListNode* head){
    std::vector<int> values = fill(head);
    std::vector<int> res(0,values.size());
    std::stack<int> mon;
    for(int i = values.size() - 1;i>=0;i--){
        while(!mon.empty() && mon.top() <= values[i])
            mon.pop();
        
        if(!mon.empty())
            res[i] = mon.top();
        mon.push(values[i]);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    ListNode* list = new ListNode(2,new ListNode(1,new ListNode(5)));
    std::vector<int> res = nextLargerNodes(list);
    for(const auto& el : res)
        std::cout<<el<<" ";
}
