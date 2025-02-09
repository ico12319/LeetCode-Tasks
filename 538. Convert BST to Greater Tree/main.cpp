#include <iostream>
#include <stack>

//538. Convert BST to Greater Tree
//Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val),left(nullptr),right(nullptr){}
};

class backward_iterator{
private:
    std::stack<node*> st;
    
    void push_right(node* root){
        node* curr = root;
        while(curr){
            st.push(curr);
            curr = curr->right;
        }
    }
    
public:
    backward_iterator(node* root){
        push_right(root);
    }
    
    backward_iterator& operator--(){
        node* curr = st.top();
        st.pop();
        if(curr->left)
            push_right(curr->left);
        return *this;
    }
    
    node* operator*(){
        return st.top();;
    }
    
    bool has_ended() const{
        return st.empty();
    }
};


node* convert_bst(node* root){
    backward_iterator iter(root);
    int sumation = 0;
    while(!iter.has_ended()){
        node* curr = *iter;
        sumation += curr->val;
        curr->val = sumation;
        --iter;
    }
    return root;
}


void destroy(node* root){
    if(!root)
        return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main(int argc, const char * argv[]) {
    node* root = new node(4);
    root->left = new node(1);
    root->left->left = new node(0);
    root->left->right = new node(2);
    root->left->right->right = new node(3);
    root->right = new node(6);
    root->right->left = new node(5);
    root->right->right = new node(7);
    root->right->right->right = new node(8);
    
    root = convert_bst(root);
    
    std::cout<<root->left->left->val<<std::endl;
    destroy(root);
}
