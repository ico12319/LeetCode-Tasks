#include <iostream>

//669. Trim a Binary Search Tree
//Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};


void in_order_traversal(TreeNode* root){
    if(!root) return;
    in_order_traversal(root->left);
    std::cout<<root->val<<" ";
    in_order_traversal(root->right);
}


TreeNode* trimBst(TreeNode* root,int low,int high){
    if (!root) return nullptr;
    
    if (root->val < low)
        return trimBst(root->right, low, high);
        
    if (root->val > high)
        return trimBst(root->left, low, high);

    root->left = trimBst(root->left, low, high);
    root->right = trimBst(root->right, low, high);
    return root;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    root->right = new TreeNode(4);
    
    
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    
    TreeNode* new_root = trimBst(root, 1, 3);
    in_order_traversal(new_root);
}
