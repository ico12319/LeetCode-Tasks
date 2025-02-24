#include <iostream>
#include <queue>

//1609. Even Odd Tree
//A binary tree is named Even-Odd if it meets the following conditions:The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};

bool is_even(int num){
    return num % 2 == 0;
}

void destroy(node* root){
    if(!root)
        return;;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

bool check_level(std::vector<int>& curr_level,int level){
    if(is_even(level)){
        for(int i = 1;i<curr_level.size();i++){
            if(curr_level[i] < curr_level[i - 1])
                return false;
        }
    }
    else{
        for(int i = 1;i<curr_level.size();i++){
            if(curr_level[i] > curr_level[i - 1])
                return false;
        }
    }
    return true;
}

bool is_even_odd_tree(node* root){
    std::queue<node*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        auto curr_level_size = q.size();
        std::vector<int> curr_level;
        for(int i = 0;i<curr_level_size;i++){
            auto curr_node = q.front();
            if(is_even(level) && is_even(curr_node->val))
                return false;
            else if(!is_even(level) && !is_even(curr_node->val))
                return false;
            q.pop();
            curr_level.push_back(curr_node->val);
            if(curr_node->left)
                q.push(curr_node->left);
            if(curr_node->right)
                q.push(curr_node->right);
            
        }
        if(!check_level(curr_level, level))
            return false;
        level++;
    }
    return true;
}
    



int main(int argc, const char * argv[]) {
    node* root = new node(1);
    root->left = new node(10);
    root->left->left = new node(3);
    root->left->left->left = new node(12);
    root->left->left->right = new node(8);
    root->right = new node(4);
    root->right->left = new node(7);
    root->right->left->left = new node(6);
    root->right->right = new node(9);
    root->right->right->right = new node(2);
    
    std::cout<<is_even_odd_tree(root)<<std::endl;
    destroy(root);
}
