#include <iostream>

//654. Maximum Binary Tree
//You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:Create a root node whose value is the maximum value in nums.Recursively build the left subtree on the subarray prefix to the left of the maximum value.Recursively build the right subtree on the subarray suffix to the right of the maximum value.Return the maximum binary tree built from nums.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};


TreeNode* build_tree(std::vector<int>& nums,int start,int end){
    if(start > end) return nullptr;
    int max = INT_MIN;
    int max_ind = INT_MIN;
    for(int i = start;i<=end;i++){
        if(nums[i] > max){
            max = nums[i];
            max_ind = i;
        }
    }
    TreeNode* root = new TreeNode(max);
    root->left = build_tree(nums, start, max_ind - 1);
    root->right = build_tree(nums, max_ind + 1, end);
    return root;
}


void destroy(TreeNode* root){
    if(!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
    
}


TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
    return build_tree(nums, 0, nums.size() - 1);
}
int main(int argc, const char * argv[]) {
    std::vector<int> nums = {3,2,1,6,0,5};
    TreeNode* root = constructMaximumBinaryTree(nums);
    destroy(root);
}
