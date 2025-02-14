#include <iostream>
#include <queue>

//2385. Amount of Time for Binary Tree to Be Infected
//You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.Each minute, a node becomes infected if:The node is currently uninfected.The node is adjacent to an infected node.Return the number of minutes needed for the entire tree to be infected.
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

void convert(node* root,std::unordered_map<int, std::vector<int>>& adj){
    if(!root)
        return;
    auto from = root->val;
    if(root->left){
        adj[from].push_back(root->left->val);
        adj[root->left->val].push_back(from);
    }
    if(root->right){
        adj[from].push_back(root->right->val);
        adj[root->right->val].push_back(from);
    }
    
    convert(root->left, adj);
    convert(root->right, adj);
}


int amount_of_time(node* root,int start){
    std::queue<int> q;
    int time = -1;
    std::unordered_map<int, std::vector<int>> adj;
    convert(root, adj);
    q.push(start);
    std::unordered_map<int, bool> visited;
    visited[start] = true;
    while(!q.empty()){
        auto curr_level_size = q.size();
        for(int i = 0;i<curr_level_size;i++){
            auto curr_node = q.front();
            q.pop();
            
            for(const auto& child : adj[curr_node]){
                if(!visited[child]){
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
        time++;
    }
    return time;
}


int main(int argc, const char * argv[]) {
    node* root = new node(1);
    root->left = new node(5);
    root->right = new node(3);
    root->left->right = new node(4);
    root->left->right->left = new node(9);
    root->left->right->right = new node(2);
    root->right->left = new node(10);
    root->right->right = new node(6);
    
    std::cout<<amount_of_time(root, 3)<<std::endl;
    destroy(root);
}
