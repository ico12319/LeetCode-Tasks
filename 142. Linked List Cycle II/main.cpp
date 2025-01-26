#include <iostream>
#include <unordered_set>

//142. Linked List Cycle II
//Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

struct node{
    int val;
    node* next;
    
    node(int val) : val(val),next(nullptr){}
};

void destroy(node* head){
    if(head)
        return;;
    while(head){
        node* to_delete = head;
        head = head->next;
        delete to_delete;
    }
}

node* detect_node(node* head){
    node* curr = head;
    std::unordered_set<node*> seen;
    while(curr){
        if(seen.contains(curr))
            return curr;
        seen.insert(curr);
        curr = curr->next;
    }
    return nullptr;
}

int main(int argc, const char * argv[]) {
    node* head = new node(1);
    head->next = new node(2);
    head->next = head;
    std::cout<<detect_node(head)->val<<std::endl;
    destroy(head);
}
