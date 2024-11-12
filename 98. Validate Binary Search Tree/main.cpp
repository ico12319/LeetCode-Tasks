#include <iostream>

//98. Validate Binary Search Tree
//Given the root of a binary tree, determine if it is a valid binary search tree (BST).

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};

void destroy(TreeNode* root){
    if(!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}
void in_order_traversal(TreeNode* root,std::vector<int>& v){
    if(!root) return;
    in_order_traversal(root->left, v);
    v.push_back(root->val);
    in_order_traversal(root->right, v);
}

bool check_for_dupicates(const std::vector<int>& v){
    for(int i = 0;i<v.size() - 1;i++){
        if(v[i] == v[i + 1]) return false;
    }
    return true;
}

bool is_valid(TreeNode* root){
    std::vector<int> v;
    in_order_traversal(root, v);
    if(!check_for_dupicates(v)) return false;
    return std::is_sorted(v.begin(), v.end());
}

int main(int argc, const char * argv[]) {
    TreeNode* rooot = new TreeNode(5);
    rooot->left = new TreeNode(1);
    rooot->right = new TreeNode(4);
    rooot->right->left = new TreeNode(3);
    rooot->right->right = new TreeNode(6);
    
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    
    std::cout<<is_valid(rooot)<<std::endl;
}
