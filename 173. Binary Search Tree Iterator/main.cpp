#include <iostream>
#include "binary_search_tree_iterator.h"

//173. Binary Search Tree Iterator

void destroy(TreeNode* root){
    if(!root) return;
    
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    
    binary_search_tree_iterator it(root);
    std::cout<<it.next()<<std::endl;
    std::cout<<it.next()<<std::endl;
    std::cout<<it.hasNext()<<std::endl;
    
    destroy(root);
}
