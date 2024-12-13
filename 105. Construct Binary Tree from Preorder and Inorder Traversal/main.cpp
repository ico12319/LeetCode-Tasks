#include <iostream>

//105. Construct Binary Tree from Preorder and Inorder Traversal
//Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

struct tree_node{
    int val;
    tree_node* left;
    tree_node* right;
    
    tree_node(int val) : val(val){}
};


void in_order(tree_node* root){
    if(!root) return;
    in_order(root->left);
    std::cout<<root->val<<" ";
    in_order(root->right);
}

void pre_order(tree_node* root){
    if(!root) return;
    std::cout<<root->val<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

using iterator = std::vector<int>::iterator;
tree_node* build_tree(iterator begin1,iterator end1,iterator begin2,iterator end2){
    if(begin1 == end1 || begin2 == end2) return nullptr;
    tree_node* root = new tree_node(*begin1);
    auto it = std::find(begin2,end2,root->val);
    auto left_size = std::distance(begin2,it);
    root->left = build_tree(begin1 + 1, begin1 + 1 + left_size,begin2,it);
    root->right = build_tree(begin1 + 1 + left_size, end1, it + 1,end2);
    return root;
}


tree_node* build(std::vector<int>& pre_order,std::vector<int>& in_order){
    tree_node* root = build_tree(pre_order.begin(), pre_order.end(),in_order.begin(),in_order.end());
    return root;
}

int main(int argc, const char * argv[]) {
   
    std::vector<int> pre_order1 = {3,9,20,15,7};
    std::vector<int> in_order1 = {9,3,15,20,7};
    tree_node* root = build(pre_order1, in_order1);
    pre_order(root);
    
}
