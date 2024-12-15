#include <iostream>

//108. Convert Sorted Array to Binary Search Tree
//Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val){}
};

using iterator = std::vector<int>::iterator;

TreeNode* build_from_range(iterator begin,iterator end){
    size_t distance = std::distance(begin, end);
    if(distance == 0) return nullptr;
    size_t mid = distance / 2;
    TreeNode* root = new TreeNode(*(begin + mid));
    root->left = build_from_range(begin, begin + mid);
    root->right = build_from_range(begin + mid + 1, end);
    return root;
}

TreeNode* build_tree(std::vector<int>& sorted){
    auto root = build_from_range(sorted.begin(), sorted.end());
    return root;
}

int main(int argc, const char * argv[]) {
    std::vector<int> sorted = {-10,-3,0,5,9};
    std::cout<<build_tree(sorted)->val<<" "<<build_tree(sorted)->left->val<<std::endl;
}
