#include <iostream>

//226. Invert Binary Tree
//Given the root of a binary tree, invert the tree, and return its root.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};


void in_order(node* root){
    if(!root) return;
    in_order(root->left);
    std::cout<<root->val<<" ";
    in_order(root->right);
}

node* invertTree(node* root) {
    if(!root) return root;
    
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main() {
    
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(7);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(9);
    
    //in_order(root);
    
    invertTree(root);
    in_order(root);
    
    
}
