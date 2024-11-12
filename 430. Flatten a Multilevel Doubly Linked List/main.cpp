#include <iostream>

//430. Flatten a Multilevel Doubly Linked List
//You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.

struct node{
    int val;
    node* next;
    node* prev;
    node* child;
    
    node(int val) : val(val),next(nullptr),prev(nullptr),child(nullptr){};
};

void destroy(node* head){
    node* curr = head;
    while(curr){
        node* to_delete = curr;
        curr = curr->next;
        delete to_delete;
    }
}

node* flatten(node* head){
    node* curr = head;
    while(curr){
        if(curr->child){
            node* temp_next = curr->next;
            node* temp_child = curr->child;
            curr->next = curr->child;
            curr->child->prev = curr;
            curr->child = nullptr;
            while(temp_child && temp_child->next)
                temp_child = temp_child->next;
            temp_child->next = temp_next;
            if(temp_next)
                temp_next->prev = temp_child;
        }
        curr = curr->next;
    }
    return head;
}


int main(int argc, const char * argv[]) {
        node* n1 = new node(1);
        node* n2 = new node(2);
        node* n3 = new node(3);
        node* n4 = new node(4);
        node* n7 = new node(7);
        node* n8 = new node(8);
        node* n9 = new node(9);
        node* n10 = new node(10);
        node* n11 = new node(11);
        node* n12 = new node(12);

        n1->next = n2;
        n2->prev = n1;
        n2->next = n3;
        n3->prev = n2;
        n3->next = n4;
        n4->prev = n3;

        n3->child = n7;
        n7->next = n8;
        n8->prev = n7;
        n8->next = n9;
        n9->prev = n8;
        n9->next = n10;
        n10->prev = n9;

        n8->child = n11;
        n11->next = n12;
        n12->prev = n11;
    
    node* n = flatten(n1);
    while(n){
        std::cout<<n->val<<" ";
        n = n->next;
    }
    
    destroy(n1);
    destroy(n);
}

