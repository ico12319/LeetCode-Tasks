#include <iostream>
#include <queue>

//2965. Find Missing and Repeated Values
//You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

struct pair_comparator{
    bool operator()(const std::pair<int,int>& p1,const std::pair<int,int>& p2) const{
        return p1.second < p2.second;
    }
};

std::vector<int> find_missing_and_repeated_values(std::vector<std::vector<int>>& grid){
    std::unordered_map<int, int> freq;
    for(const auto& arr : grid){
        for(const auto& el : arr)
            freq[el]++;
    }
    
    std::vector<std::pair<int,int>> temp(freq.begin(),freq.end());
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,pair_comparator> max_heap(temp.begin(),temp.end());
    std::vector<int> res;
    res.push_back(max_heap.top().first);
    int max_number = grid.size() * grid.size();
    int min_number = 1;
    for(int i = min_number;i<=max_number;i++){
        if(!freq.contains(i))
            res.push_back(i);
    }
    return res;
    
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};
    auto res = find_missing_and_repeated_values(grid);
    for(const auto& el : res)
        std::cout<<el<<" ";
    
}
