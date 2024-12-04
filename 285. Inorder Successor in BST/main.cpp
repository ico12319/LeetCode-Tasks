#include <iostream>

//285. Inorder Successor in BST
//Given a binary search tree and a node in it, find the in-order successor of that node in the BST.The successor of a node p is the node with the smallest key greater than p.val.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val){}
};

node* in_order_successor(node* root,node* p){
    if(!root) return root;
    int smallest = INT_MAX;
    node* curr = root;
    node* to_return = nullptr;
    while(curr){
        if(p->val < curr->val){
            if(smallest > curr->val){
                smallest = curr->val;
                to_return = curr;
            }
            curr = curr->left;
            
        }
        else
            curr = curr->right;
    }
    return to_return;
}

int main(int argc, const char * argv[]) {
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);
    //root->right->right = new node(4);
    std::cout<<in_order_successor(root, root->right->left)->val;
}
