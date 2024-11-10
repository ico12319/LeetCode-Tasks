#include <iostream>

//617. Merge Two Binary Trees
//You are given two binary trees root1 and root2.Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
    TreeNode(int val,TreeNode* left,TreeNode* right) : val(val),left(left),right(right){}
};


TreeNode* merge(TreeNode* root1,TreeNode* root2){
   if(!root1 && !root2)
        return nullptr;
    if(!root1) return root2;
    if(!root2) return root1;
    
    root1->val += root2->val;
    root1->left = merge(root1->left, root2->left);
    root1->right = merge(root1->right, root2->right);
    
    return root1;
}

std::vector<int> res;
void preorder(TreeNode* root){
    if(!root)
        return;
    res.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
}

std::vector<int> preorderTraversal(TreeNode* root){
    preorder(root);
    return res;
}


void free(TreeNode* root){
    if(!root)
        return;
    free(root->left);
    free(root->right);
    delete root;
}

int main(int argc, const char * argv[]) {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);
    
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->left->right = new TreeNode(4);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(7);
    
    TreeNode* newRoot = merge(root1, root2);
    std::vector<int> res = preorderTraversal(newRoot);
    for(const auto& el : res)
        std::cout<<el<<" ";
    
    free(root1);
}
