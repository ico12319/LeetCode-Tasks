#include <iostream>

//2294. Partition Array Such That Maximum Difference Is K
//You are given an integer array nums and an integer k. You may partition nums into one or more subsequences such that each element in nums appears in exactly one of the subsequences.Return the minimum number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is at most k.A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

int partitionArray(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int min = nums[0];
    int br = 0;
    for (const auto& num : nums) {
        if (num - min > k) {
            min = num;
            br++;
        }
    }
    return br + 1;
}


int main(int argc, const char * argv[]) {
    std::vector<int> nums = {3,6,1,2,5};
    int k = 2;
    std::cout<<partitionArray(nums, k)<<std::endl;
}
