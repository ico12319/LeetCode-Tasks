#include <iostream>
#include <unordered_set>
#include <stack>

//653. Two Sum IV - Input is a BST
//Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};


class binary_search_tree_iterator{
private:
    std::stack<TreeNode*> nodes;
    bool forward;
    
    void push(TreeNode* root){
        TreeNode* curr = root;
        while(curr){
            nodes.push(curr);
            curr = forward ? curr->left : curr->right;
        }
    }
    
public:
    binary_search_tree_iterator(TreeNode* root,bool forward) : forward(forward){
        push(root);
    }
    
    int get_next(){
        TreeNode* top = nodes.top();
        nodes.pop();
        int val = top->val;
        if(forward)
            push(top->right);
        else
            push(top->left);
        
        return val;
    }
};



bool find_target(TreeNode* root,int k){
    if(!root) return false;
    
    binary_search_tree_iterator forward(root, true);
    binary_search_tree_iterator backward(root, false);
    
    int left_ptr = forward.get_next();
    int right_ptr = backward.get_next();
    while(left_ptr < right_ptr){
        if(left_ptr + right_ptr == k)
            return true;
        else if(left_ptr + right_ptr > k)
            right_ptr = backward.get_next();
        else if(left_ptr + right_ptr < k)
            left_ptr = forward.get_next();
    }
    return false;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    //root->right->right = new TreeNode(7);
    
    
    std::cout<<find_target(root, 28)<<std::endl;
}
