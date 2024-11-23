#include <iostream>
#include <queue>

//515. Find Largest Value in Each Tree Row
//Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};


std::vector<int> largestValues(TreeNode* root) {
    std::queue<TreeNode*> nodes;
    nodes.push(root);
    std::vector<int> result;
    while(!nodes.empty()){
        int max_value = INT_MIN;
        size_t size = nodes.size();
        for(int i = 0;i<size;i++){
            TreeNode* curr = nodes.front();
            nodes.pop();
            max_value = std::max(max_value, curr->val);
            if(curr->left)
                nodes.push(curr->left);
            if(curr->right)
                nodes.push(curr->right);
        }
        result.push_back(max_value);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    
    std::vector<int> m = largestValues(root);
    for(const auto& el : m)
        std::cout<<el<<" ";
}
