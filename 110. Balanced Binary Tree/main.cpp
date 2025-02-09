#include <iostream>

//110. Balanced Binary Tree
//Given a binary tree, determine if it is height-balanced.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};


int height(node* root){
    if(!root)
        return 0;
    return 1 + std::max(height(root->left),height(root->right));
}

bool is_balanced(node* root){
    if(!root)
        return true;
    if(std::abs(height(root->left)-height(root->right)) > 1)
       return false;
       
    return is_balanced(root->left) && is_balanced(root->right);
}

void destroy(node* root){
    if(!root)
        return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main(int argc, const char * argv[]) {
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->left->left = new node(4);
    root->left->right = new node(3);
    root->left->left->right = new node(4);
    root->right = new node(2);
    
    
    std::cout<<is_balanced(root)<<std::endl;
    
    destroy(root);
}
