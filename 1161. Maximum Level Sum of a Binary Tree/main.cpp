#include <iostream>
#include <queue>

//1161. Maximum Level Sum of a Binary Tree
//Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

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


int level_with_max_sum(node* root){
    int level = 1;
    int max_sum = INT_MIN;
    int max_level = INT_MIN;
    std::queue<node*> q;
    q.push(root);
    while(!q.empty()){
        auto curr_level_size = q.size();
        int curr_sum = 0;
        for(int i = 0;i<curr_level_size;i++){
            node* curr = q.front();
            q.pop();
            curr_sum += curr->val;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        if(curr_sum > max_sum){
            max_sum = curr_sum;
            max_level = level;
        }
        level++;
    }
    return max_level;
}

int main(int argc, const char * argv[]) {
    node* root = new node(1);
    root->left = new node(7);
    root->right = new node(0);
    root->left->left = new node(7);
    root->left->right = new node(-8);
    
    std::cout<<level_with_max_sum(root)<<std::endl;
    destroy(root);
}
