#include <iostream>

//450. Delete Node in a BST
//Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
    TreeNode(int val,TreeNode* left,TreeNode* right) : val(val),left(left),right(right){}
};

void destroy(TreeNode* root){
    if(!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

void in_order_traversal(TreeNode* root){
    if(!root) return;
    in_order_traversal(root->left);
    std::cout<<root->val<<" ";
    in_order_traversal(root->right);
}

TreeNode** find_min(TreeNode** root){
    TreeNode** curr = root;
    while((*curr)->left)
        curr = &((*curr)->left);
    return curr;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode** curr = &root;
    while(*curr){
        if(key < (*curr)->val)
            curr = &(*curr)->left;
        else if(key > (*curr)->val)
            curr = &(*curr)->right;
        else break;
    }
    if(!(*curr))
        return root;
    TreeNode* toDelete = *curr;
    if(!(*curr)->left && !(*curr)->right)
        *curr = nullptr;
    else if(!(*curr)->left && (*curr)->right)
        *curr = (*curr)->right;
    else if(!(*curr)->right && (*curr)->left)
        *curr = (*curr)->left;
    else{
        TreeNode** min_in_right_subtree = find_min(&(*curr)->right);
        *curr = *min_in_right_subtree;
        *min_in_right_subtree = (*min_in_right_subtree)->right;
        (*curr)->left = toDelete->left;
        (*curr)->right = toDelete->right;
    }
    delete toDelete;
    return root;
}


int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    root = deleteNode(root, 3);
    in_order_traversal(root);
    destroy(root);
    
}
