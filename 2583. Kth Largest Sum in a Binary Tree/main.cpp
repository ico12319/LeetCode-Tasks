#include <iostream>
#include <queue>

//2583. Kth Largest Sum in a Binary Tree
//You are given the root of a binary tree and a positive integer k.The level sum in the tree is the sum of the values of the nodes that are on the same level.Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.Note that two nodes are on the same level if they have the same distance from the root.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val){}
};


long long k_th_largest_level_sum(node* root,int k){
    std::queue<node*> levels;
    levels.push(root);
    std::priority_queue<long long,std::vector<long long>,std::greater<>> sums;
    while(!levels.empty()){
        auto curr_level_size = levels.size();
        long long sum = 0;
        for(int i = 0;i<curr_level_size;i++){
            node* curr_node = levels.front();
            levels.pop();
            sum+=curr_node->val;
            if(curr_node->left)
                levels.push(curr_node->left);
            if(curr_node->right)
                levels.push(curr_node->right);
        }
        if(sums.size() < k)
            sums.push(sum);
        else if(sum > sums.top()){
            sums.pop();
            sums.push(sum);
        }
    }
    return sums.top();
}

int main(int argc, const char * argv[]) {
    node* root = new node(5);
    root->left = new node(8);
    root->left->left = new node(2);
    root->left->left->left = new node(4);
    root->left->right = new node(1);
    root->right = new node(9);
    root->right->left = new node(3);
    root->right->right = new node(7);
    
    int k = 2;
    std::cout<<k_th_largest_level_sum(root, k)<<std::endl;
}
