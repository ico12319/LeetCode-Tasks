#include <iostream>
#include <deque>

//101. Symmetric Tree
//Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};


bool is_mirrored(node* left,node* right){
    if(!left && !right) return true;
    if(!left || !right) return false;
    if(left->val != right->val) return false;
    return is_mirrored(left->left,right->right) && is_mirrored(left->right,right->left);
}

bool is_symmetric(node* root){
    if(!root) return true;
    return is_mirrored(root->left, root->right);
}
int main(int argc, const char * argv[]) {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(3);
    
    std::cout<<is_symmetric(root)<<std::endl;
}
