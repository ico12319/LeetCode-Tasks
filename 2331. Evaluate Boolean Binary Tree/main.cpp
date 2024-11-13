#include <iostream>

//2331. Evaluate Boolean Binary Tree
//You are given the root of a full binary tree with the following properties:Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True.Non-leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.The evaluation of a node is as follows:If the node is a leaf node, the evaluation is the value of the node, i.e. True or False.Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.Return the boolean result of evaluating the root node.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};

void destroy(TreeNode* root){
    if(!root) return;;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

bool eval(TreeNode* root){
    if(!root->left && !root->right)
        return root->val;
    
    if(root->val == 2)
        return eval(root->left) || eval(root->right);
    else
        return eval(root->left) && eval(root->right);
}

int main(int argc, const char * argv[]) {
    
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->right->left = new TreeNode(0);
    root2->right->right = new TreeNode(1);
    
    std::cout<<eval(root2)<<std::endl;
    destroy(root2);
    
}
