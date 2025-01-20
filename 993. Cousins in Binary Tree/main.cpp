#include <iostream>
#include <queue>

//993. Cousins in Binary Tree
//Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.Two nodes of a binary tree are cousins if they have the same depth with different parents.Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};

void destroy(node* root){
    if(!root)
        return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

bool are_cousins(node* root,int x,int y){
    std::queue<std::pair<node*,int>> nodes;
    nodes.push({root,-1});
    int curr_level = 0;
    std::vector<std::pair<int,int>> cousins_candidate;
    while(!nodes.empty()){
        auto curr_level_size = nodes.size();
        for(int i = 0;i<curr_level_size;i++){
            node* curr = nodes.front().first;
            if(curr->val == x || curr->val == y)
                cousins_candidate.push_back({nodes.front().second,curr_level});
            nodes.pop();
            if(curr->left)
                nodes.push({curr->left,curr->val});
            if(curr->right)
                nodes.push({curr->right,curr->val});
        }
        curr_level++;
    }
    return cousins_candidate[0].first != cousins_candidate[1].first && cousins_candidate[0].second == cousins_candidate[1].second;
}

int main(int argc, const char * argv[]) {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->right->right = new node(5);
    
    
    std::cout<<are_cousins(root, 4, 5)<<std::endl;
    
    destroy(root);
}
