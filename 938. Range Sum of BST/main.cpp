#include <iostream>

//938. Range Sum of BST
//Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};


void range_sum(TreeNode* root,int low,int high,int& sum){
    if(!root) return;
    if(root->val < low)
        range_sum(root->right, low, high,sum);
    else if(root->val > high)
        range_sum(root->left, low, high, sum);
    
    else{
        sum+=root->val;
        range_sum(root->left, low, high, sum);
        range_sum(root->right, low, high, sum);
    }
}


int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    range_sum(root, low, high, sum);
    return sum;
}


int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->left->left->left = new TreeNode(1);
    root->left->right->left = new TreeNode(6);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(18);
    
    int sum = 0;
    range_sum(root, 6, 10, sum);
    std::cout<<sum<<std::endl;
}
