#include <iostream>

//347. Top K Frequent Elements
//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any orde

bool customCmp(std::pair<int,int>& a,std::pair<int,int>& b){
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

std::unordered_map<int, int> fillMap(const std::vector<int>& nums){
    std::unordered_map<int, int> timesOccur;
    for(const auto& el : nums){
        if(timesOccur.find(el) != timesOccur.end())
            timesOccur[el]++;
        else
            timesOccur[el] = 1;
    }
    return timesOccur;
}

std::vector<std::pair<int,int>>sortByFrequency(std::vector<int>& nums){
    std::unordered_map<int, int> timesOccur = fillMap(nums);
    std::vector<std::pair<int,int>> pairs(timesOccur.begin(),timesOccur.end());
    std::sort(pairs.begin(),pairs.end(),customCmp);
    return pairs;
}

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::vector<int> res;
    std::vector<std::pair<int,int>> pairs = sortByFrequency(nums);
    for(int i = 0;i<k;i++)
        res.push_back(pairs[i].first);
    return res;
}


int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,1,1,2,2,3};
    std::vector<int> topK = topKFrequent(nums, 2);
    for(const auto& el : topK)
        std::cout<<el<<" ";
    }
