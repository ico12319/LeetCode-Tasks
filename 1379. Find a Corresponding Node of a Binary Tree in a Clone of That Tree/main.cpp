#include <iostream>

//1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
//Given two binary trees original and cloned and given a reference to a node target in the original tree.The cloned tree is a copy of the original tree.Return a reference to the same node in the cloned tree.Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};

void destroy(node* root){
    if(!root)
        return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

void get_target_copy_helper(node* original,node* cloned,node* target, node*& searched){
    if(!original)
        return;
    if(original == target){
        searched = cloned;
        return;
    }
    get_target_copy_helper(original->left, cloned->left, target, searched);
    get_target_copy_helper(original->right, cloned->right, target,searched);
}

node* get_target_copy(node* original,node* cloned,node* target){
    node* searched = nullptr;
    get_target_copy_helper(original, cloned, target,searched);
    return searched;
    
}

int main(int argc, const char * argv[]) {
    node* root = new node(7);
    root->left = new node(4);
    root->right = new node(3);
    root->right->right = new node(19);
    root->right->left = new node(6);
    
    
    node* root2 = new node(7);
    root2->left = new node(4);
    root2->right = new node(3);
    root2->right->right = new node(19);
    root2->right->left = new node(6);
    
    std::cout<<get_target_copy(root, root2, root->right)->val<<std::endl;
    
    destroy(root);
    destroy(root2);
}
