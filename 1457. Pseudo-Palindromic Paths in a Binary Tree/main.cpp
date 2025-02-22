#include <iostream>

//1457. Pseudo-Palindromic Paths in a Binary Tree
//Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

constexpr size_t MIN_NUMBER = 0;
constexpr size_t MAX_NUMBER = 9;

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};

bool can_form_palindrome(std::vector<int>& occur_count){
    int counter = 0;
    for(int i = 0;i<occur_count.size();i++){
        if(occur_count[i] % 2 != 0)
            counter++;
    }
    return counter <= 1;
}

void pseudo_palindromic_paths_helper(node* root,int& count,std::vector<int>& occur_conter){
    if(!root)
        return;
    occur_conter[root->val - MIN_NUMBER]++;
    if(!root->left && !root->right){
        if(can_form_palindrome(occur_conter))
            count++;
    }
    pseudo_palindromic_paths_helper(root->left, count, occur_conter);
    pseudo_palindromic_paths_helper(root->right, count,occur_conter);
    occur_conter[root->val - MIN_NUMBER]--;
}

int count_pseudo_palindromic_paths(node* root){
    int count = 0;
    std::vector<int> occur_count(MAX_NUMBER - MIN_NUMBER + 1,0);
    pseudo_palindromic_paths_helper(root, count, occur_count);
    return count;
}

void destroy(node* root){
    if(!root)
        return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main(int argc, const char * argv[]) {
    node* root = new node(2);
    root->left = new node(1);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->left->right->right = new node(1);
    root->right = new node(1);
    
    std::cout<<count_pseudo_palindromic_paths(root)<<std::endl;
    destroy(root);
}
