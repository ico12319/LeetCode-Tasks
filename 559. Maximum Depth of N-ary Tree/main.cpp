#include <iostream>
#include <queue>

//559. Maximum Depth of N-ary Tree
//Given a n-ary tree, find its maximum depth.The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

struct node{
    int val;
    std::vector<node*> children;
    
    node(int val) : val(val){}
};

void destroy(node* root){
    if(!root)
        return;
    for(auto& child : root->children)
        destroy(child);
    delete root;
}

int maximum_depth(node* root){
    std::queue<node*> q;
    q.push(root);
    int depth = 0;
    while(!q.empty()){
        auto curr_level_size = q.size();
        for(int i = 0;i<curr_level_size;i++){
            node* curr = q.front();
            q.pop();
            for(const auto& child : curr->children){
                if(child)
                    q.push(child);
            }
        }
        depth++;
    }
    return depth;
}

int main(int argc, const char * argv[]) {
    node* root = new node(1);
    root->children.push_back(new node(3));
    root->children.push_back(new node(2));
    root->children.push_back(new node(4));
    root->children.at(0)->children.push_back(new node(5));
    root->children.at(0)->children.push_back(new node(6));
    
    std::cout<<maximum_depth(root)<<std::endl;
    destroy(root);
}
