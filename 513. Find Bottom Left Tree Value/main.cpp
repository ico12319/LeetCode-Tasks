#include <iostream>
#include <queue>

//513. Find Bottom Left Tree Value
//Given the root of a binary tree, return the leftmost value in the last row of the tree

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};



void find_leaf_with_longest_path(TreeNode* root,int path,int& leaf,int& max_path){
    if(!root) return;
    if(!root->left && !root->right){
        if(max_path < path){
            max_path = path;
            leaf = root->val;
        }
    }
    path++;
    find_leaf_with_longest_path(root->left, path, leaf, max_path);
    find_leaf_with_longest_path(root->right, path, leaf, max_path);
}


int findBottomLeftValue(TreeNode* root) {
    int path = 0;
    int leaf = 0;
    int max_path = 0;
    find_leaf_with_longest_path(root, path, leaf, max_path);
    return leaf;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    
    int path = 0;
    int leaf = 0;
    int max_path = 0;
    find_leaf_with_longest_path(root2, path, leaf, max_path);
    std::cout<<leaf<<std::endl;
}
