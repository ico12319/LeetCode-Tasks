#include <iostream>
#include <queue>

//199. Binary Tree Right Side View
//Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};

std::vector<std::vector<int>>right_side(TreeNode* root){
    std::vector<std::vector<int>> levels;
    std::queue<TreeNode*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        std::vector<int> v;
        size_t size = nodes.size();
        for(int i = 0;i<size;i++){
            TreeNode* curr = nodes.front();
            nodes.pop();
            v.push_back(curr->val);
            if(curr->left)
                nodes.push(curr->left);
            if(curr->right)
                nodes.push(curr->right);
            
        }
        levels.push_back(v);
    }
    return levels;
}

std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> result;
    std::vector<std::vector<int>> levels_traversed = right_side(root);
    for(int i = 0;i<levels_traversed.size();i++)
        result.push_back(levels_traversed[i][levels_traversed[i].size() - 1]);
    return result;
}


int main(int argc, const char * argv[]) {
    
}
