#include <iostream>

//230. Kth Smallest Element in a BST
//Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};


void in_order_traversal(TreeNode* root,std::vector<int>& v){
    if(!root) return;
    in_order_traversal(root->left, v);
    v.push_back(root->val);
    in_order_traversal(root->right, v);
}

int kthSmallest(TreeNode* root, int k){
    std::vector<int> traversed;
    in_order_traversal(root, traversed);
    return traversed[k - 1];
    
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    
    std::cout<<kthSmallest(root, 1)<<std::endl;
}
