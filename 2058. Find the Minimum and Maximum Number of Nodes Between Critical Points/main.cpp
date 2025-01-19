#include <iostream>

//2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
//A critical point in a linked list is defined as either a local maxima or a local minima.A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

struct node{
    int val;
    node* next;
    
    node(int val) : val(val){}
    node(int val,node* next) : val(val),next(next){}
};

void destroy(node* head){
    while(head){
        node* to_delete = head;
        head = head->next;
        delete to_delete;
    }
}

std::vector<int> nodes_between_critical_points(node* head){
    node* curr = head;
    node* dummy = new node(INT_MAX);
    dummy->next = curr;
    node* prev = dummy;
    
    bool is_first_maxima_found = false;
    int min_distance = INT_MAX;
    int max_distance = INT_MIN;
    int curr_distance = 0;
    int curr_min_distance = 0;
    while(curr && curr->next){
        if(prev->val != INT_MAX && curr->next){
            if((curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val)){
                if(!is_first_maxima_found)
                    is_first_maxima_found = true;
                else{
                    max_distance = std::max(max_distance, curr_distance);
                    min_distance = std::min(min_distance, curr_min_distance);
                    curr_min_distance = 0;
                }
            }
        }
        curr = curr->next;
        prev = prev->next;
        if(is_first_maxima_found){
            curr_distance++;
            curr_min_distance++;
        }
    }
    delete dummy;
    
    if(min_distance == INT_MAX)
        return {-1,-1};
    
    return {min_distance,max_distance};
}

int main(int argc, const char * argv[]) {
    node* head = new node(3);
    head->next = new node(1);

    
    auto distances = nodes_between_critical_points(head);
    for(const auto& el : distances)
        std::cout<<el<<" ";
    
    destroy(head);
    
}
