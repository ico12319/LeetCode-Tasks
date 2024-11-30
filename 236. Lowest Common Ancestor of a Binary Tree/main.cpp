#include <iostream>
#include <stack>

//236. Lowest Common Ancestor of a Binary Tree
//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).

struct tree_node{
    int val;
    tree_node* left;
    tree_node* right;
    
    tree_node(int val) : val(val){}
};

tree_node* lowest_common_ancestor(tree_node* root, tree_node* p, tree_node* q) {
        if(root == nullptr || root == p || root == q) return root;

        tree_node* left = lowest_common_ancestor(root->left, p, q);
        tree_node* right = lowest_common_ancestor(root->right, p, q);
        
        if(left == nullptr)
            return right;
        else if(right == nullptr)
            return left;
        else
            return root;
    }

int main(int argc, const char * argv[]) {

    tree_node* root = new tree_node(3);
    root->left = new tree_node(5);
    root->right = new tree_node(1);
    root->left->left = new tree_node(6);
    root->left->right = new tree_node(2);
    root->left->right->left = new tree_node(7);
    root->left->right->right = new tree_node(4);
    root->right->left = new tree_node(0);
    root->right->right = new tree_node(8);
    
    std::cout<<lowest_common_ancestor(root, root->left->right->left,root->left->right->right)->val<<std::endl;
    
}
