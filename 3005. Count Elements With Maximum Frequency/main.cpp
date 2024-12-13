#include <iostream>
#include <queue>

//3005. Count Elements With Maximum Frequency
//You are given an array nums consisting of positive integers.Return the total frequencies of elements in nums such that those elements all have the maximum frequency.The frequency of an element is the number of occurrences of that element in the array.

struct pair_comparator{
    bool operator()(const std::pair<int,int>& p1,const std::pair<int,int>& p2) const{
        return p1.second < p2.second;
    }
};

int max_frequency_elements(std::vector<int>& nums){
    std::unordered_map<int, int> freq;
    for(const auto& el : nums)
        freq[el]++;
    std::vector<std::pair<int,int>> temp(freq.begin(),freq.end());
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,pair_comparator> pq(temp.begin(),temp.end());
    
    auto max_freq = pq.top().second;
    int counter = 0;
    while(!pq.empty()){
        if(max_freq != pq.top().second)
            return counter;
        counter+=pq.top().second;
        pq.pop();
    }
    return counter;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,2,3,4,5};
    std::cout<<max_frequency_elements(nums)<<std::endl;
}
