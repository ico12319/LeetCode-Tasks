#include <iostream>

//965. Univalued Binary Tree
//A binary tree is uni-valued if every node in the tree has the same value.Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};


bool is_univalued_helper(node* root,int& root_value){
    if(!root)
        return true;
    if(root->val != root_value)
        return false;
    return is_univalued_helper(root->left, root_value) && is_univalued_helper(root->right, root_value);
}

bool is_univalued(node* root){
    if(!root)
        return true;
    int root_value = root->val;
    return is_univalued_helper(root, root_value);
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
    root->left = new node(1);
    root->right = new node(1);
    root->left->left = new node(2);
    
    std::cout<<is_univalued(root)<<std::endl;
    destroy(root);
}
