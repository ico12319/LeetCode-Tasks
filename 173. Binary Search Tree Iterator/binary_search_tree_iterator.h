#pragma once
#include <iostream>
#include <stack>
#include "TreeNode.h"

class binary_search_tree_iterator{
private:
    std::stack<TreeNode*> most_left;
    
    void push_left(TreeNode* root);
public:
    binary_search_tree_iterator(TreeNode* root);
    int next();
    bool hasNext() const;
};
