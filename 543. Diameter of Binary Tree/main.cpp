#include <iostream>

//543. Diameter of Binary Tree
//Given the root of a binary tree, return the length of the diameter of the tree.The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.The length of a path between two nodes is represented by the number of edges between them.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};


int height(node* root,int& diameter){
    if(!root)
        return 0;
    int left_height = height(root->left, diameter);
    int right_height = height(root->right, diameter);
    
    diameter = std::max(diameter, left_height + right_height);
    return 1 + std::max(left_height, right_height);
}

int diameter_of_binary_tree(node* root){
    if(!root)
        return 0;
    int d = 0;
    height(root, d);
    return d;
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
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    
    std::cout<<diameter_of_binary_tree(root)<<std::endl;
    destroy(root);
}
