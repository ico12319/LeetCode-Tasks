#include <iostream>

//257. Binary Tree Paths
//Given the root of a binary tree, return all root-to-leaf paths in any order.A leaf is a node with no children.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val){}
};

void binary_tree_paths_helper(node* root,std::vector<std::string>& res,std::string& temp){
    if(!root) return;
    size_t orig_len = temp.size();
    temp+=std::to_string(root->val);
    if(root->left || root->right)
        temp+="->";
    else if(!root->left && !root->right)
        res.push_back(temp);
    binary_tree_paths_helper(root->left, res,temp);
    binary_tree_paths_helper(root->right, res,temp);
    temp.resize(orig_len);
    
}

auto binary_tree_paths(node* root){
    std::vector<std::string> res;
    std::string res2;
    binary_tree_paths_helper(root, res,res2);
    return res;
}

int main(int argc, const char * argv[]) {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);
    auto res = binary_tree_paths(root);
    for(const auto& el : res){
        std::cout<<el<<" ";
    }
    std::cout<<std::endl;
}
