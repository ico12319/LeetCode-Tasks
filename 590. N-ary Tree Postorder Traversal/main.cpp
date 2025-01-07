#include <iostream>

//590. N-ary Tree Postorder Traversal
//Given the root of an n-ary tree, return the postorder traversal of its nodes' values.Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

struct node{
    int val;
    std::vector<node*> children;
    
    node(int val) : val(val){}
};

void destroy(node* root){
    if(!root) return;
    for(const auto& child : root->children)
        destroy(child);
    delete root;
}

void post_order_helper(node* root,std::vector<int>& order){
    if(!root) return;
    for(const auto& child : root->children)
        post_order_helper(child, order);
    order.push_back(root->val);
}

std::vector<int> post_order(node* root){
    if(!root)
        return {};
    std::vector<int> order;
    post_order_helper(root, order);
    return order;
}

int main(int argc, const char * argv[]) {
    node* root = new node(1);
    root->children.push_back(new node(3));
    root->children.push_back(new node(2));
    root->children.push_back(new node(4));
    root->children.at(0)->children.push_back(new node(5));
    root->children.at(0)->children.push_back(new node(6));
    
    auto order = post_order(root);
    for(const auto& el : order)
        std::cout<<el<<" ";
    
    destroy(root);
}
