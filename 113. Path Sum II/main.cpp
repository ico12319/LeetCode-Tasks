#include <iostream>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void has_sum(TreeNode* root,int targetSum,int res,std::vector<int> v,std::vector<std::vector<int>>& v2){
    if(!root) return;
    res+=root->val;
    v.push_back(root->val);
    
    if(res == targetSum && !root->left && !root->right)
        v2.push_back(v);
    if(!root->left && !root->right)
        v.pop_back();
    
    has_sum(root->left, targetSum, res,v,v2);
    has_sum(root->right, targetSum, res,v,v2);
    
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
    std::vector<int> v;
    std::vector<std::vector<int>> v2;
    has_sum(root,targetSum,0,v,v2);
    return v2;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    
   
    std::vector<std::vector<int>> v2 = pathSum(root, 22);
   
}
