#include <iostream>
#include <queue>

//23. Merge k Sorted Lists
//You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.Merge all the linked-lists into one sorted linked-list and return it.

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int val) : val(val),next(nullptr){}
    ListNode(int val,ListNode* next) : val(val),next(next){}
};

struct list_comparator{
    bool operator()(const ListNode* a, const ListNode* b) const{
        return a->val > b->val;
    }
};


ListNode* merge_k_sorted(std::vector<ListNode*>& lists){
    std::priority_queue<ListNode*,std::vector<ListNode*>,list_comparator> pq;
    for(int i = 0;i<lists.size();i++){
        if(lists[i])
            pq.push(lists[i]);
    }
    
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    while(!pq.empty()){
        ListNode* temp = pq.top();
        curr->next = temp;
        curr = curr->next;
        if(temp->next) pq.push(temp->next);
        pq.pop();
    }
    return dummy->next;
    
}

int main(int argc, const char * argv[]) {
    
    ListNode* head = new ListNode(1,new ListNode(2,new ListNode(3)));
    ListNode* head2 = new ListNode(1,new ListNode(8,new ListNode(9)));
    std::vector<ListNode*> lists = {head,head2};
    
    ListNode* merged = merge_k_sorted(lists);
    while(merged){
        std::cout<<merged->val<<" ";
        merged = merged->next;
    }
    
    
    
    
    
}
