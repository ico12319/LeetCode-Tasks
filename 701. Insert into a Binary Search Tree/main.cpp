#include <iostream>

//701. Insert into a Binary Search Tree
//You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
    //TreeNode(int val,TreeNode* left,TreeNode* right) : val(val),l
};


TreeNode* insertIntoBST(TreeNode* root,int val){
    if(!root) return new TreeNode(val);
    
    TreeNode** curr = &root;
    while(*curr){
        if((*curr)->val < val)
            curr = &(*curr)->right;
        else if((*curr)->val > val)
            curr = &(*curr)->left;
        else
            return nullptr;
    }
    *curr = new TreeNode(val);
    return root;
}


void in_order_traversal(TreeNode* root){
    if(!root) return;
    in_order_traversal(root->left);
    std::cout<<root->val<<" ";
    in_order_traversal(root->right);
}


int main() {
    
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    TreeNode* n = insertIntoBST(root, 5);
    in_order_traversal(n);
    
    
}
