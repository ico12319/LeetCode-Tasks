#include <iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
    TreeNode(int val,TreeNode* left,TreeNode* right) : val(val),left(left),right(right){}
};


int findAllSums(TreeNode* root,int& goodNodesCount,int& nodesCount){
    if(!root) return 0;
    
    int leftCount = 0;
    int rightCount = 0;
    
    int leftSum = findAllSums(root->left,goodNodesCount,leftCount);
    int rightSum = findAllSums(root->right,goodNodesCount,rightCount);
    
    int currSum = leftSum + rightSum + root->val;
    int currCount = 1 + leftCount + rightCount;
    
    int average = currSum / currCount;
    if(root->val == average)
        goodNodesCount++;
    nodesCount = currCount;
    return currSum;
}

int averageOfSubtree(TreeNode* root) {
    int goodNodes = 0;
    int totalNodes = 0;
    findAllSums(root, goodNodes, totalNodes);
    return goodNodes;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    
    root->right->right = new TreeNode(6);
}
