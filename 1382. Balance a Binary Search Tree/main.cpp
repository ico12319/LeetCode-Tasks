#include <iostream>

//1382. Balance a Binary Search Tree
//Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
    node(int val ,node* left,node* right) : val(val),left(left),right(right){}
};

void in_order_traversal(node* root,std::vector<int>& sorted){
    if(!root) return;
    in_order_traversal(root->left, sorted);
    sorted.push_back(root->val);
    in_order_traversal(root->right, sorted);
}

using iterator = std::vector<int>::iterator;
node* build_from_range(iterator begin,iterator end){
    auto distance = std::distance(begin, end);
    if(distance < 0) return nullptr;
    if(distance == 0)
        return new node(*begin);
    auto mid = distance / 2;
    return new node(*(begin + mid),build_from_range(begin, begin + mid),build_from_range(begin + mid + 1, end));
}

node* balance_bst(node* root){
    std::vector<int> sorted;
    in_order_traversal(root, sorted);
    return build_from_range(sorted.begin(), sorted.end() - 1);
}

int main(int argc, const char * argv[]) {
    node* root = new node(1);
    root->right = new node(2);
    root->right->right = new node(3);
    root->right->right->right = new node(4);
    
    
    root = balance_bst(root);
}
