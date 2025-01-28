#include <iostream>
#include <queue>

//623. Add One Row to Tree
//Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.Note that the root node is at depth 1.The adding rule is:Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.cur's original left subtree should be the left subtree of the new left subtree root.cur's original right subtree should be the right subtree of the new right subtree root.If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.

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

void in_order(node* root){
    if(!root)
        return;
    in_order(root->left);
    std::cout<<root->val<<" ";
    in_order(root->right);
}

node* add_one_row(node* root,int val,int depth){
    if(depth == 1){
        node* new_root = new node(val);
        new_root->left = root;
        return new_root;
    }
    int curr_depth = 1;
    std::queue<node*> q;
    q.push(root);
    while(!q.empty()){
        auto curr_level_size = q.size();
        for(int i = 0;i<curr_level_size;i++){
            node* curr = q.front();
            q.pop();
            
            if(curr_depth == depth - 1){
                if(curr->left && curr->right){
                    node* orig_left = curr->left;
                    node* orig_right = curr->right;
                    curr->left = new node(val);

                    curr->left->left = orig_left;
                    
                    curr->right = new node(val);
                    curr->right->right = orig_right;
                }
                else if(curr->left){
                    node* orig_left = curr->left;
                    curr->left = new node(val);
                    curr->left->left = orig_left;
                }
                else if(curr->right){
                    node* orig_right = curr->right;
                    curr->right = new node(val);
                    curr->right->right = orig_right;
                }
                if(!curr->left)
                    curr->left = new node(val);
                if(!curr->right)
                    curr->right = new node(val);
            }
            else{
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        curr_depth++;
        if(curr_depth == depth)
            break;
    }
    return root;
}

int main(int argc, const char * argv[]) {
    node* root = new node(4);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(1);
    
    root = add_one_row(root, 1, 3);
    in_order(root);
    
    destroy(root);
}
