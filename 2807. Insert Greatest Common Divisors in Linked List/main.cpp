#include <iostream>

//2807. Insert Greatest Common Divisors in Linked List
//Given the head of a linked list head, in which each node contains an integer value.Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.Return the linked list after insertion.The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

struct node{
    int val;
    node* next;
    
    node(int val) : val(val),next(nullptr){}
};

int find_gcd(int a,int b){
    if(a < b)
        std::swap(a,b);
    if(b == 0)
        return a;
    return find_gcd(b, a % b);
}

node* insert_greatest_common_divisor(node* head){
    if(!head || !head->next)
        return head;
    node* curr = head;
    while(curr && curr->next){
        auto gcd = find_gcd(curr->val, curr->next->val);
        node* to_add = new node(gcd);
        node* orig_next = curr->next;
        curr->next = to_add;
        to_add->next = orig_next;
        curr = to_add->next;
    }
    return head;
}

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


int main(int argc, const char * argv[]) {
    node* head = new node(18);
    head->next = new node(6);
    head->next->next = new node(10);
    head->next->next->next = new node(3);
    
    node* new_head = insert_greatest_common_divisor(head);
    while(new_head){
        std::cout<<new_head->val<<" ";
        new_head = new_head->next;
    }
    
    destroy(head);
    destroy(new_head);
}
