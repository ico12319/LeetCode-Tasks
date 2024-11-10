#include <iostream>

//129. Sum Root to Leaf Numbers
//You are given the root of a binary tree containing digits from 0 to 9 only.Each root-to-leaf path in the tree represents a number.Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.A leaf node is a node with no children.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
    TreeNode(int val,TreeNode* left,TreeNode* right) : val(val),left(left),right(right){}
};


void extractSum(TreeNode* root,int res,int& sum){
    if(!root)
        return;
    res = (res * 10) + root->val;
    if(!root->left && !root->right){
        sum+=res;
        return;
    }
    if(root->left) extractSum(root->left, res, sum);
    if(root->right) extractSum(root->right, res, sum);
}

int sumNumbers(TreeNode* root){
    int sum = 0;
    extractSum(root, 0, sum);
    return sum;
}

void free(TreeNode* root){
    if(!root)
        return;
    
    free(root->left);
    free(root->right);
    delete root;
}

int main(int argc, const char * argv[]) {
   
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    std::cout<<sumNumbers(root)<<std::endl;
    free(root);
}
