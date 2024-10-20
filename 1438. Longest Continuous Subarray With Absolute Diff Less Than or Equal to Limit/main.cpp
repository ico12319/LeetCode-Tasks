#include <iostream>
#include <set>

//1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
//Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

int longestSubarray(std::vector<int>& nums,int limit){
    std::multiset<int> sortedOrder;
    const size_t size = nums.size();
    int leftPointer = 0;
    int longestSize = 0;
    for(int i = 0;i<size;i++){
        sortedOrder.insert(nums[i]);
        if(*sortedOrder.rbegin() - *sortedOrder.begin() > limit){
            sortedOrder.erase(sortedOrder.find(nums[leftPointer]));
            leftPointer++;
        }
        longestSize = std::max(longestSize,i - leftPointer + 1);
    }
    return longestSize;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,5,9,14};
    int limit = 3;
    std::cout<<longestSubarray(nums, limit)<<std::endl;
}
