#include <iostream>

//725. Split Linked List in Parts
//Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.Return an array of the k parts.

struct node{
    int val;
    node* next;
    
    node(int val) : val(val),next(nullptr){}
};

int size(node* head){
    node* curr = head;
    int size = 0;
    while(curr){
        size++;
        curr = curr->next;
    }
    return size;
}

std::vector<node*> split_list_to_parts(node* head,int k){
    auto size_of_list = size(head);
    int elements_part = size_of_list / k;
    int parts_with_bigger_size = size_of_list % k;
    std::vector<node*> res;
    int iters = 0;
    node* curr = head;
    
    for(int i = 0;i<k;i++){
        node* new_list = new node(0);
        node* to_push = new_list;
        while(curr && iters != elements_part){
            new_list->next = new node(curr->val);
            curr = curr->next;
            new_list = new_list->next;
            iters++;
        }
        if(parts_with_bigger_size != 0){
            new_list->next = new node(curr->val);
            new_list = new_list->next;
            curr = curr->next;
            parts_with_bigger_size--;
        }
        iters = 0;
        
        res.push_back(to_push->next);
        
    }
    return res;
}

void print(node* head){
    node* curr = head;
    while(curr){
        std::cout<<curr->val<<" ";
        curr = curr->next;
    }
}

void destroy(node* head){
    node* curr = head;
    while(curr){
        node* to_delete = curr;
        curr = curr->next;
        delete to_delete;
    }
}

int main(int argc, const char * argv[]) {
    
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    head->next->next->next->next->next->next = new node(7);
    head->next->next->next->next->next->next->next = new node(8);
    head->next->next->next->next->next->next->next->next = new node(9);
    head->next->next->next->next->next->next->next->next->next = new node(10);
    
    auto res = split_list_to_parts(head, 3);
    for(const auto& el : res){
        print(el);
        std::cout<<std::endl;
    }
}
