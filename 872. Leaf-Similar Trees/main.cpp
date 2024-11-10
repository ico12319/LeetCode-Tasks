#include <iostream>

//872. Leaf-Similar Trees
//Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
    TreeNode(int val,TreeNode* left,TreeNode* right) : val(val),left(left),right(right){}
};

void findLeafValues(TreeNode* root,std::vector<int>& leaves){
    if(!root)
        return;
    if(!root->left && !root->right)
        leaves.push_back(root->val);
    
    findLeafValues(root->left,leaves);
    findLeafValues(root->right,leaves);
}

std::vector<int> extract(TreeNode* root1){
    std::vector<int> leaves;
    findLeafValues(root1,leaves);
    return leaves;
}

bool areLeafSimilar(TreeNode* root1,TreeNode* root2){
    std::vector<int> leaves1 = extract(root1);
    std::vector<int> leaves2 = extract(root2);
    
    return leaves1 == leaves2;
}

void free(TreeNode* root){
    if(!root)
        return;
    free(root->left);
    free(root->right);
    delete root;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(2);
    
    std::cout<<areLeafSimilar(root, root2)<<std::endl;
    free(root);
    free(root2);
}
