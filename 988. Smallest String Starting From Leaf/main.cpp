#include <iostream>

//988. Smallest String Starting From Leaf
//You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.As a reminder, any shorter prefix of a string is lexicographically smaller.For example, "ab" is lexicographically smaller than "aba".A leaf of a node is a node that has no children.

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

void extract_words(node* root,std::string& curr_word,std::string& smallest_word,std::unordered_map<int, char>& map){
    if(!root)
        return;
    curr_word += map[root->val];
    if(!root->right && !root->left){
        std::string temp = curr_word;
        std::reverse(temp.begin(),temp.end());
        if(smallest_word.empty() || smallest_word > temp)
            smallest_word = temp;
        curr_word.pop_back();
        return;
    }
    extract_words(root->left, curr_word, smallest_word,map);
    extract_words(root->right, curr_word, smallest_word,map);
    curr_word.pop_back();
}

std::string smallest_from_leaf(node* root){
    std::unordered_map<int,char> map;
    map.insert({0,'a'});
    map.insert({1,'b'});
    map.insert({2,'c'});
    map.insert({3,'d'});
    map.insert({4,'e'});
    map.insert({5,'f'});
    map.insert({6,'g'});
    map.insert({7,'h'});
    map.insert({8,'i'});
    map.insert({9,'j'});
    map.insert({10,'k'});
    map.insert({11,'l'});
    map.insert({12,'m'});
    map.insert({13,'n'});
    map.insert({14,'o'});
    map.insert({15,'p'});
    map.insert({16,'q'});
    map.insert({17,'r'});
    map.insert({18,'s'});
    map.insert({19,'t'});
    map.insert({20,'u'});
    map.insert({21,'v'});
    map.insert({22,'w'});
    map.insert({23,'x'});
    map.insert({24,'y'});
    map.insert({25,'z'});
    std::string curr;
    std::string smallest;
    extract_words(root, curr, smallest, map);
    return smallest;
}


int main(int argc, const char * argv[]) {
    node* root = new node(25);
    root->left = new node(1);
    root->right = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(0);
    root->right->right = new node(2);
    
    auto smallest_word = smallest_from_leaf(root);
    std::cout<<smallest_word<<std::endl;
    destroy(root);
    
}
