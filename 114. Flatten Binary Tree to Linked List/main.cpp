#include <iostream>

//114. Flatten Binary Tree to Linked List
//Given the root of a binary tree, flatten the tree into a "linked list":The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.The "linked list" should be in the same order as a pre-order traversal of the binary tree.


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};


void pre_order(TreeNode* root,std::vector<int>& v){
    if(!root) return;
    
    v.push_back(root->val);
    pre_order(root->left, v);
    pre_order(root->right,v);
}

void flatten(TreeNode* root){
    std::vector<int> traversed_tree;
    pre_order(root, traversed_tree);
    TreeNode* curr = root;
    curr->left = nullptr;
    
    for(int i = 1;i<traversed_tree.size();i++){
        TreeNode* temp = new TreeNode(traversed_tree[i]);
        curr->right = temp;
        curr = curr->right;
        
    }
    
    
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    
    flatten(root);
    while(root){
        std::cout<<root->val<<" ";
        root = root->right;
    }
    
    
}
