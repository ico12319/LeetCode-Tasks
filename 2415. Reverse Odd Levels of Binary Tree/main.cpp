#include <iostream>
#include <queue>

//2415. Reverse Odd Levels of Binary Tree
//Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.
//Return the root of the reversed tree.A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.The level of a node is the number of edges along the path between it and the root node.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};

bool is_even(int num){
    return !(num & 1);
}


void in_order(node* root){
    if(!root) return;
    in_order(root->left);
    std::cout<<root->val<<" ";
    in_order(root->right);
}


void reverse_helper(node* root1,node* root2,int level){
    if(!root1 || !root2) return;
    
    if(!is_even(level)){
        int temp = root1->val;
        root1->val = root2->val;
        root2->val = temp;
    }
    reverse_helper(root1->left,root2->right,level + 1);
    reverse_helper(root1->right,root2->left,level + 1);
}

node* reverse_odd_levels(node* root){
    reverse_helper(root->left, root->right, 1);
    return root;
}

int main(int argc, const char * argv[]) {
    node* root = new node(2);
    root->left = new node(3);
    root->right = new node(5);
    root->left->left = new node(8);
    root->left->right = new node(13);
    root->right->left = new node(21);
    root->right->right = new node(34);
}
