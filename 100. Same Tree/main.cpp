#include <iostream>

//100. Same Tree
//Given the roots of two binary trees p and q, write a function to check if they are the same or not.Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};


bool is_same_tree(TreeNode* p,TreeNode* q){
    if((!p && q) || (p && !q)) return false;
    if(!p && !q) return true;
    
    if(p->val != q->val)
        return false;
    return is_same_tree(p->left, q->left) && is_same_tree(p->right, q->right);
}

int main(int argc, const char * argv[]) {
}
