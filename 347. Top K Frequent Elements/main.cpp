#include <iostream>
#include <queue>

//347. Top K Frequent Elements
//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

struct pair_comparator{
    bool operator()(const std::pair<int,int>& p1,const std::pair<int,int>& p2) const{
        return p1.second < p2.second;
    }
};

std::vector<int> top_k_frequent(std::vector<int>& nums,int k){
    if(nums.empty()) return {};
    std::unordered_map<int, int> freq;
    for(const auto& num : nums)
        freq[num]++;
    std::vector<std::pair<int,int>> temp(freq.begin(),freq.end());
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,pair_comparator> pq(temp.begin(),temp.end());
    std::vector<int> res;
    for(int i = 0;i<k;i++){
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1};
    int k = 1;
    auto res = top_k_frequent(nums, k);
    for(const auto& el : res)
        std::cout<<el<<" ";
    std::cout<<std::endl;
}
