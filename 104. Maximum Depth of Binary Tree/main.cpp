#include <iostream>
#include <queue>

//104. Maximum Depth of Binary Tree
//Given the root of a binary tree, return its maximum depth.A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};


int maxDepth(TreeNode* root){
    if(!root) return 0;
    std::queue<TreeNode*> levels;
    levels.push(root);
    int number_of_levels = 0;
  
    while(!levels.empty()){
        int node_count_level = levels.size();
        number_of_levels++;
        for(int i = 0;i<node_count_level;i++){
            TreeNode* curr = levels.front();
            
            levels.pop();
            if(curr->left)
                levels.push(curr->left);
            if(curr->right)
                levels.push(curr->right);
        }
    }
    return number_of_levels;
}


int main(int argc, const char * argv[]) {
   
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    std::cout<<maxDepth(root2)<<std::endl;
    
}
