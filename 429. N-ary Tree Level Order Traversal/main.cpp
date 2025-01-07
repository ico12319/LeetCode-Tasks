#include <iostream>
#include <queue>

//429. N-ary Tree Level Order Traversal
//Given an n-ary tree, return the level order traversal of its nodes' values.Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

struct node{
    int val;
    std::vector<node*> children;
    
    node(int val) : val(val){}
};

void destroy(node* root){
    if(!root) return;
    for(const auto& child : root->children){
        if(child)
            destroy(child);
    }
    delete root;
}

std::vector<std::vector<int>> level_order(node* root){
    std::queue<node*> levels;
    std::vector<std::vector<int>> level_order;
    levels.push(root);
    
    while(!levels.empty()){
        std::vector<int> curr_level;
        auto curr_level_size = levels.size();
        for(int i = 0;i<curr_level_size;i++){
            node* curr_top = levels.front();
            levels.pop();
            curr_level.push_back(curr_top->val);
            
            for(const auto& child : curr_top->children){
                if(child)
                    levels.push(child);
            }
        }
        level_order.push_back(curr_level);
    }
    return level_order;
}

int main(int argc, const char * argv[]) {
    node* root = new node(1);
    root->children.push_back(new node(3));
    root->children.push_back(new node(2));
    root->children.push_back(new node(4));
    root->children.at(0)->children.push_back(new node(5));
    root->children.at(0)->children.push_back(new node(6));
    
    auto traversed_levels = level_order(root);
    for(const auto& level : traversed_levels){
        for(const auto& el : level)
            std::cout<<el<<" ";
        std::cout<<std::endl;
    }
    
    destroy(root);
    
}
