#include <iostream>
#include <queue>

//107. Binary Tree Level Order Traversal II
//Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};

std::vector<std::vector<int>> levelOrderBottom(node* root) {
    std::queue<node*> levels;
    std::vector<std::vector<int>> result;
    levels.push(root);
    while(!levels.empty()){
        size_t size = levels.size();
        std::vector<int> to_fill;
        for(int i = 0;i<size;i++){
            node* curr = levels.front();
            levels.pop();
            to_fill.push_back(curr->val);
            if(curr->left)
                levels.push(curr->left);
            if(curr->right)
                levels.push(curr->right);
        }
        result.push_back(to_fill);
    }
    std::reverse(result.begin(), result.end());
    return result;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
