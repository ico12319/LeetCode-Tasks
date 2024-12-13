#include <iostream>
#include <queue>
#include <unordered_set>

//2441. Largest Positive Integer That Exists With Its Negative
//Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.Return the positive integer k. If there is no such integer, return -1.

int find_max(std::vector<int>& nums){
    std::priority_queue<int> pq(nums.begin(),nums.end());
    std::unordered_set<int> set(nums.begin(),nums.end());
    while(!pq.empty()){
        if(set.contains(-1 * pq.top()))
            return pq.top();
        pq.pop();
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {-1,10,6,7,-7,1};
    std::cout<<find_max(nums)<<std::endl;
}
