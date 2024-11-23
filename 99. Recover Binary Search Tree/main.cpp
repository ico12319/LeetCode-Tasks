#include <iostream>

//99. Recover Binary Search Tree
//You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};


void in_order(TreeNode* root,TreeNode*& first,TreeNode*& second,TreeNode*& prev){
    if(!root) return;
    
    in_order(root->left, first, second, prev);
    if(prev && prev->val > root->val){
        if(!first)
            first = prev;
        second = root;
    }
    prev = root;
    in_order(root->right, first, second, prev);
}

void recover_tree(TreeNode* root){
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    
    in_order(root, first, second,prev);
    std::swap(first->val, second->val);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
