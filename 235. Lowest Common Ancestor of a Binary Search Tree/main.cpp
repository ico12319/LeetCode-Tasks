#include <iostream>

//235. Lowest Common Ancestor of a Binary Search Tree
//Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val){}
};


TreeNode* lowest_common_ancestor(TreeNode* root,TreeNode* p,TreeNode* q){
    if(!root) return root;
    while(root){
        if(p->val > root->val && q->val > root->val)
            root = root->right;
        else if(p->val < root->val && q->val < root->val)
            root = root->left;
        else
            return root;
    }
    
    return nullptr;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    
    std::cout<<lowest_common_ancestor(root, root->left, root->right)->val<<std::endl;
}
