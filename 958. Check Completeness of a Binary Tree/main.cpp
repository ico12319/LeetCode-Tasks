#include <iostream>
#include <queue>

//958. Check Completeness of a Binary Tree
//Given the root of a binary tree, determine if it is a complete binary tree.In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

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
    destroy(root->left);
    delete root;
}

int get_height(node* root){
    if(!root)
        return 0;
    return 1 + std::max(get_height(root->left), get_height(root->right));
}


bool is_complete_binary_tree(node* root){
    std::queue<node*> q;
    std::vector<int> last_level;
    q.push(root);
    int curr_level = 1;
    int height = get_height(root);
    
    while(!q.empty()){
        auto curr_level_size = q.size();
        for(int i = 0;i<curr_level_size;i++){
            node* curr = q.front();
            q.pop();
            if(curr_level < height - 1){
                if(!curr->left || !curr->right)
                    return false;
            }
            else if(curr_level == height - 1){
                if(!curr->left)
                    last_level.push_back(-1);
                else if(curr->left)
                    last_level.push_back(curr->left->val);
                if(!curr->right)
                    last_level.push_back(-1);
                else if(curr->right)
                    last_level.push_back(curr->right->val);
            }
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            
        }
        curr_level++;
    }
    for(int i = 0;i<last_level.size();i++){
        if(i + 1 < last_level.size() && last_level[i] == -1 && last_level[i + 1] != -1)
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(5);
    root->left->right = new node(6);
    //root->right->right = new node(6);
    destroy(root);
    
    std::cout<<is_complete_binary_tree(root)<<std::endl;
    
    
}
