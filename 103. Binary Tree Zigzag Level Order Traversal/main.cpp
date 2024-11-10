#include <iostream>
#include <queue>

//103. Binary Tree Zigzag Level Order Traversal
//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
    TreeNode(int val,TreeNode* left,TreeNode* right) : val(val),left(left),right(right){}
};

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root){
    if(!root) return {};
    std::vector<std::vector<int>> result;
    std::queue<TreeNode*> levels;
    levels.push(root);
    bool toReverse = true;
    while(!levels.empty()){
        size_t levelBredth = levels.size();
        std::vector<int> currLevel;
        for(int i = 0;i<levelBredth;i++){
            TreeNode* curr = levels.front();
            levels.pop();
            
            currLevel.push_back(curr->val);
            if(curr->left)
                levels.push(curr->left);
            if(curr->right)
                levels.push(curr->right);
        }
        if(toReverse){
            std::reverse(currLevel.begin(), currLevel.end());
            toReverse = false;
        }
        else{
            toReverse = true;
        }
        result.push_back(currLevel);
    }
    return result;
}

void print(std::vector<int>& v){
    for(auto it = v.begin();it!=v.end();it++)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
}


int main(int argc, const char * argv[]) {
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(13);
    
    std::vector<std::vector<int>> result = zigzagLevelOrder(root);
    for(int i = 0;i<result.size();i++)
        print(result[i]);
   
}
