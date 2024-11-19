#include <iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : val(val),left(nullptr),right(nullptr){}
};


void print(const std::vector<int>& v){
    for(const auto& el : v)
        std::cout<<el<<" ";
    std::cout<<std::endl;
}

void in_order_traversal(TreeNode* root,std::vector<int>& el){
    if(!root) return;
    in_order_traversal(root->left, el);
    el.push_back(root->val);
    in_order_traversal(root->right, el);
}

std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    std::vector<int> el1;
    in_order_traversal(root1, el1);
    print(el1);
    std::vector<int> el2;
    in_order_traversal(root2, el2);
    print(el2);
    if(!root1) return el2;
    if(!root2) return el1;
    std::vector<int> result(el1.size() + el2.size(),0);
    std::merge(el1.begin(), el1.end(), el2.begin(), el2.end(), result.begin());
    return result;
    
}

int main(int argc, const char * argv[]) {
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);
    
    std::vector<int> v = getAllElements(root1, root2);
    for(const auto& el : v)
        std::cout<<el<<" ";
}
