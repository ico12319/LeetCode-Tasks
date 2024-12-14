#include <iostream>
#include <queue>

//508. Most Frequent Subtree Sum
//Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

struct pair_compare{
    bool operator()(const std::pair<int,int>& p1,const std::pair<int,int>& p2) const{
        return p1.second < p2.second;
    }
};

struct node{
    int val;
    node* left;
    node* right;
    
    node(int val) : val(val){}
};

int sum_frequency(node* root,std::unordered_map<int,int>& freq){
    if(!root) return 0;
    
    int left_sum = sum_frequency(root->left, freq);
    int right_sum = sum_frequency(root->right,freq);
    
    int curr_sum = root->val + left_sum + right_sum;
    freq[curr_sum]++;
    return curr_sum;
}

std::vector<int> find_freqeunt(node* root){
    if(!root) return {};
    std::vector<int> res;
    std::unordered_map<int, int> freq_map;
    sum_frequency(root, freq_map);
    std::vector<std::pair<int,int>> temp(freq_map.begin(),freq_map.end());
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,pair_compare> pq(temp.begin(),temp.end());
    auto max_freq = pq.top().second;
    while(!pq.empty()){
        if(max_freq != pq.top().second)
            break;
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}


int main(int argc, const char * argv[]) {
    node* root = new node(5);
    root->left = new node(2);
    root->right = new node(-5);
}
