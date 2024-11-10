#include <iostream>

//94. Binary Tree Inorder Traversal
//Given the root of a binary tree, return the inorder traversal of its nodes' values.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
    TreeNode(int val,TreeNode* left,TreeNode* right) : val(val),left(left),right(right){}
};

std::vector<int> ans;

void inorder(TreeNode* root){
    if(!root)
        return;
    
    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
}

std::vector<int> inorderTraversal(TreeNode* root){
    inorder(root);
    return ans;
}

void free(TreeNode* root){
    if(!root)
        return;
    
    free(root->left);
    free(root->right);
    delete root;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    
    std::vector<int> res = inorderTraversal(root);
    for(const auto& el : res)
        std::cout<<el<<" ";
    free(root);
}
