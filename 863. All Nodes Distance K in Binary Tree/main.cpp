#include <iostream>
#include <queue>

//863. All Nodes Distance K in Binary Tree
//Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.You can return the answer in any order.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};

void destroy(node* root){
    if(!root)
        return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

void convert(node* root,std::unordered_map<int,std::vector<int>>& adj){
    if(!root)
        return;
    auto from = root->val;
    if(root->left){
        auto to = root->left->val;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    if(root->right){
        auto to = root->right->val;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    convert(root->left, adj);
    convert(root->right, adj);
}

std::vector<int> distance_k(node* root,node* target,int k){
    std::vector<int> res;
    auto start = target->val;
    std::queue<int> q;
    std::unordered_map<int, bool> visited;
    visited[start] = true;
    std::unordered_map<int,std::vector<int>> adj;
    convert(root, adj);
    
    int curr_level = 0;
    q.push(start);
    while(!q.empty()){
        auto curr_level_size = q.size();
        for(int i = 0;i<curr_level_size;i++){
            auto curr_node = q.front();
            q.pop();
            
            if(curr_level == k)
                res.push_back(curr_node);
            
            for(const auto& child : adj[curr_node]){
                if(!visited[child]){
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
        curr_level++;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    node* root = new node(3);
    root->left = new node(5);
    root->left->left = new node(6);
    root->left->right = new node(2);
    root->left->right->left = new node(7);
    root->left->right->right = new node(4);
    root->right = new node(1);
    root->right->left = new node(0);
    root->right->right = new node(8);
    
    auto distance = distance_k(root, root->left, 2);
    for(const auto& node : distance)
        std::cout<<node<<" ";
    
    destroy(root);
    
}
