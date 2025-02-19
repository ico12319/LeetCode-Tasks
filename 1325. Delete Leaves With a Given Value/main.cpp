#include <iostream>

//1325. Delete Leaves With a Given Value
//Given a binary tree root and an integer target, delete all the leaf nodes with value target.Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};

bool delete_helper(node** root,int target){
    if(!(*root))
        return false;
    if(!(*root)->left && !(*root)->right && (*root)->val == target){
        node* to_delete = *root;
        *root = nullptr;
        delete to_delete;
        return true;
    }
    return delete_helper(&(*root)->left, target) || delete_helper(&(*root)->right, target);
}

node* remove_leaf_nodes(node* root,int target){
    while(delete_helper(&root, target));
    return root;
}

void in_order(node* root){
    if(!root)
        return;
    in_order(root->left);
    std::cout<<root->val<<std::endl;
    in_order(root->right);
}

void destroy(node* root){
    if(!root)
        return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main(int argc, const char * argv[]) {
    
    node* root = new node(1);
    root->left = new node(3);
    root->left->left = new node(3);
    root->left->right = new node(2);
    root->right = new node(3);
    
    root = remove_leaf_nodes(root, 3);
    in_order(root);
    destroy(root);
}
