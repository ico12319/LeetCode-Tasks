#pragma once

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
    TreeNode(int val,TreeNode* left,TreeNode* right) : val(val),left(left),right(right){}
};
