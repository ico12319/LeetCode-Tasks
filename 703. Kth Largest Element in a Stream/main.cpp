#include <iostream>


//783. Minimum Distance Between BST Nodes
//Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};


void in_order(TreeNode* root,std::vector<int>& v){
    if(!root) return;
    in_order(root->left,v);
    v.push_back(root->val);
    in_order(root->right, v);
}


int min_diff(TreeNode* root){
    int min = INT_MAX;
    std::vector<int> sorted;
    in_order(root,sorted);
    for(int i = 1;i<sorted.size();i++)
        min = std::min(min,sorted[i] - sorted[i - 1]);
    return min;
}

int main() {
    
    
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(7);
    //root->right->left = new TreeNode(12);
    //root->right->right = new TreeNode(49);
    
    int curr = 0;
    int min = INT_MAX;
    min_difference(root, curr, min);
    std::cout<<min<<std::endl;
}
