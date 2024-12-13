#include <iostream>
#include <queue>

//1481. Least Number of Unique Integers after K Removals
//Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

struct pair_comparator{
    bool operator()(const std::pair<int,int>& p1,const std::pair<int,int>& p2) const{
        return p1.second > p2.second;
    }
};

size_t find_least_num_of_unique_ints(std::vector<int>& arr,int k){
    std::unordered_map<int, int> freq;
    for(const auto& el : arr)
        freq[el]++;
    std::vector<std::pair<int,int>> temp(freq.begin(),freq.end());
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,pair_comparator> pq(temp.begin(),temp.end());
    for(int i = 0;i<k;i++){
        auto curr_smallest = pq.top();
        freq[pq.top().first]--;
        pq.pop();
        if(freq[curr_smallest.first] == 0)
            freq.erase(curr_smallest.first);
        else
            pq.push({curr_smallest.first,freq[curr_smallest.first]});
        
    }
    return freq.size();
}


int main(int argc, const char * argv[]) {
    std::vector<int> arr = {4,3,1,1,3,3,2};
    int k = 3;
    std::cout<<find_least_num_of_unique_ints(arr, k)<<std::endl;
}
