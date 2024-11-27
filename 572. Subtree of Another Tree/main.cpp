#include <iostream>

//572. Subtree of Another Tree
//Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};

void are_same_trees(TreeNode* root1,TreeNode* root2,bool& flag){
    if((!root1 && root2)||(root1 && !root2)){
        flag = false;
        return;
    }
    if(!root1 && !root2){
        return;
    }
    
    if(root1->val != root2->val){
        flag = false;
        return;
    }
    are_same_trees(root1->left, root2->left,flag);
    if(!flag) return;
    are_same_trees(root1->right, root2->right,flag);
}

bool same_trees(TreeNode* root1,TreeNode* root2){
   
    bool flag = true;
    are_same_trees(root1, root2,flag);
    return flag;
}

void is_subtree_helper(TreeNode* root,TreeNode* sub_root,bool& flag){
    if(flag || !root) return;
    if(root->val == sub_root->val && same_trees(root, sub_root)){
        flag = true;
        return;
    }
    is_subtree_helper(root->left,sub_root,flag);
    is_subtree_helper(root->right, sub_root,flag);
}

bool is_subtree(TreeNode* root,TreeNode* sub_root){
    if(!sub_root) return true;
    if(!root) return false;
    bool flag = false;
    is_subtree_helper(root, sub_root,flag);
    return flag;
}

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->right->right->right = new TreeNode(1);
    root->right->right->right->right = new TreeNode(1);
    root->right->right->right->right->right = new TreeNode(1);
    root->right->right->right->right->right->right = new TreeNode(1);
    root->right->right->right->right->right->right->right = new TreeNode(1);
    root->right->right->right->right->right->right->right->right = new TreeNode(2);
    
    
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(1);
    root2->right->right= new TreeNode(1);
    root2->right->right->right = new TreeNode(1);
    root2->right->right->right->right = new TreeNode(1);
    root2->right->right->right->right->right = new TreeNode(2);
    
    std::cout<<is_subtree(root, root2)<<std::endl;
}
