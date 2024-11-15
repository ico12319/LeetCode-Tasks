#include <iostream>
#include <queue>

//102. Binary Tree Level Order Traversal
//Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};


void print(const std::vector<int>& v){
    for(auto it = v.begin();it!=v.end();it++)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
}


std::vector<std::vector<int>>level_order(TreeNode* root){
    if(!root) return {};
    std::queue<TreeNode*> levels;
    std::vector<std::vector<int>> result;
    levels.push(root);
    while(!levels.empty()){
        std::vector<int> curr_level;
        size_t curr_size = levels.size();
        for(int i = 0;i<curr_size;i++){
            TreeNode* curr = levels.front();
            levels.pop();
            
            curr_level.push_back(curr->val);
            if(curr->left)
                levels.push(curr->left);
            if(curr->right)
                levels.push(curr->right);
        }
        result.push_back(curr_level);
    }
    return result;
}



int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    std::vector<std::vector<int>> levels = level_order(root);
    for(const auto& el : levels)
        print(el);
}
