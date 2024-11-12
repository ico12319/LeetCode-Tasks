#include <stdio.h>
#include "binary_search_tree_iterator.h"

void binary_search_tree_iterator::push_left(TreeNode* root){
    TreeNode* curr = root;
    while(curr){
        most_left.push(curr);
        curr = curr->left;
    }
}

binary_search_tree_iterator::binary_search_tree_iterator(TreeNode* root){
    push_left(root);
}

int binary_search_tree_iterator::next(){
    TreeNode* to_return = most_left.top();
    most_left.pop();
    if(to_return->right)
        push_left(to_return->right);
    return to_return->val;
}

bool binary_search_tree_iterator::hasNext() const{
    return most_left.size() > 0;
}



