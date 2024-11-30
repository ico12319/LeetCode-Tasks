#include <iostream>

//1302. Deepest Leaves Sum
//Given the root of a binary tree, return the sum of values of its deepest leaves.

struct tree_node{
    int val;
    tree_node* left;
    tree_node* right;
    
    tree_node(int val) : val(val){}
};

void find_deepest_leaves_sum_helper(tree_node* root,int& sum,size_t level,size_t& max_level){
    if(!root) return;
    if(!root->left && !root->right){
        if(max_level < level){
            max_level = level;
            sum = 0;
            sum+=root->val;
        }
        else if(max_level == level)
            sum+=root->val;
    }
    find_deepest_leaves_sum_helper(root->left, sum, level + 1, max_level);
    find_deepest_leaves_sum_helper(root->right, sum, level + 1, max_level);
}

int find_deepest_sum(tree_node* root){
    int sum = 0;
    size_t max_level = 0;
    size_t level = 0;
    find_deepest_leaves_sum_helper(root, sum, level, max_level);
    return sum;
}

int main(int argc, const char * argv[]) {
    tree_node* root = new tree_node(1);
    root->left = new tree_node(2);
    root->right = new tree_node(3);
    root->left->left = new tree_node(4);
    root->left->right = new tree_node(5);
    root->left->left->left = new tree_node(7);
    root->right->right = new tree_node(6);
    root->right->right->right = new tree_node(8);
    
    tree_node* root2 = new tree_node(6);
    root2->left = new tree_node(7);
    root2->right = new tree_node(8);
    root2->left->left = new tree_node(2);
    root2->left->left->left = new tree_node(9);
    root2->left->right = new tree_node(7);
    root2->left->right->left = new tree_node(1);
    root2->left->right->right = new tree_node(4);
    root2->right->left = new tree_node(1);
    root2->right->right = new tree_node(3);
    root2->right->right->right = new tree_node(5);
    
    tree_node* root3 = new tree_node(50);
    root3->right = new tree_node(54);
    root3->right->left = new tree_node(98);
    root3->right->right = new tree_node(6);
    root3->right->right->right = new tree_node(34);
    
    std::cout<<find_deepest_sum(root)<<std::endl;
    std::cout<<find_deepest_sum(root2)<<std::endl;
    std::cout<<find_deepest_sum(root3)<<std::endl;
}
