#include <iostream>

//589. N-ary Tree Preorder Traversal
//Given the root of an n-ary tree, return the preorder traversal of its nodes' values.Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

struct node{
    int val;
    std::vector<node*> children;
    
    node(int val) : val(val){}
};

void destroy(node* root){
    if(!root) return;
    for(const auto& chid : root->children)
        destroy(chid);
    delete root;
}

void pre_order_helper(node* root,std::vector<int>& pre_order){
    if(!root) return;
    pre_order.push_back(root->val);
    for(const auto& child : root->children)
        pre_order_helper(child, pre_order);
}

std::vector<int> pre_order(node* root){
    if(!root) return {};
    std::vector<int> order;
    pre_order_helper(root, order);
    return order;
    
}

int main(int argc, const char * argv[]) {
    node* root = new node(1);
    root->children.push_back(new node(3));
    root->children.push_back(new node(2));
    root->children.push_back(new node(4));
    root->children.at(0)->children.push_back(new node(5));
    root->children.at(0)->children.push_back(new node(6));
    
    auto order = pre_order(root);
    for(const auto& el : order)
        std::cout<<el<<" ";
    
    destroy(root);
}
