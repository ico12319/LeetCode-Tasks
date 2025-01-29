#include <iostream>
#include <queue>

//501. Find Mode in Binary Search Tree
//Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};

struct comparator{
    bool operator()(const std::pair<int,int>& p1,const std::pair<int,int>& p2){
        return p1.second < p2.second;
    }
};

void find_mode_helper(node* root,std::unordered_map<int,int>& key_value){
    if(!root)
        return;
    find_mode_helper(root->left,key_value);
    key_value[root->val]++;
    find_mode_helper(root->right,key_value);
}

std::vector<int> find_mode(node* root){
    std::unordered_map<int,int> map;
    find_mode_helper(root, map);
    std::vector<std::pair<int,int>> temp(map.begin(),map.end());
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,comparator> pq(temp.begin(),temp.end());
    std::vector<int> medians;
    auto max_ocurr = pq.top().second;
    while(!pq.empty()){
        if(max_ocurr != pq.top().second)
            break;
        medians.push_back(max_ocurr);
        pq.pop();
    }
    return medians;
}



int main(int argc, const char * argv[]) {
    node* root = new node(1);
    root->right = new node(2);
    root->right->left = new node(2);
    std::cout<<find_mode(root)<<std::endl;
}
