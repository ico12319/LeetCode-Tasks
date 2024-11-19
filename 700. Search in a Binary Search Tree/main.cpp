#include <iostream>

//700. Search in a Binary Search Tree
//You are given the root of a binary search tree (BST) and an integer val.Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};


TreeNode* search_bst(TreeNode* root,int val){
    TreeNode* curr = root;
    while(curr){
        if(curr->val < val)
            curr = curr->right;
        else if(curr->val > val)
            curr = curr->left;
        else
            return curr;
    }
    return nullptr;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
