#include <iostream>
#include <queue>

//3066. Minimum Operations to Exceed Threshold Value II
//You are given a 0-indexed integer array nums, and an integer k.In one operation, you will:Take the two smallest integers x and y in nums.Remove x and y from nums.Add min(x, y) * 2 + max(x, y) anywhere in the array.
//Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.

int min_operations(const std::vector<int>& nums,int k){
    std::priority_queue<int,std::vector<int>,std::greater<int>> pq(nums.begin(),nums.end());
    int operations_needed = 0;
    while(!pq.empty()){
        auto min = pq.top();
        pq.pop();
        if(min >= k)
            return operations_needed;
        auto next_min = pq.top();
        pq.pop();
        operations_needed++;
        pq.push(min * 2 + next_min);
    }
    return operations_needed;
}


int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,1,2,4,9};
    int k = 20;
    std::cout<<min_operations(nums, k)<<std::endl;
}
