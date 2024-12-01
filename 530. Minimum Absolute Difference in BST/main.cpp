#include <iostream>

//530. Minimum Absolute Difference in BST
//Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val){}
};

void minimum_abs_difference_helper(node* root,int& diff,int& min_diff){
    if(!root) return;
    minimum_abs_difference_helper(root->left,diff,min_diff);
    diff = std::abs(diff - root->val);
    if(diff < min_diff)
        min_diff = diff;
    diff = root->val;
    minimum_abs_difference_helper(root->right, diff, min_diff);
}

int min_abs_difference(node* root){
    if(!root) return 0;
    int diff = INT_MAX;
    int min_dff = INT_MAX;
    minimum_abs_difference_helper(root, diff, min_dff);
    return min_dff;
}

int main(int argc, const char * argv[]) {
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    
    node* root1 = new node(1);
    root1->left = new node(0);
    root1->right = new node(48);
    root1->right->left = new node(12);
    root1->right->right = new node(49);
    
    node* root2 = new node(5);
    root2->left = new node(4);
    root2->right = new node(7);
    
    std::cout<<min_abs_difference(root2)<<std::endl;
}
