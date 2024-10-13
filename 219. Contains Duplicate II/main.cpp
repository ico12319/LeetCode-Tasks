#include <iostream>
#include <unordered_map>

//219. Contains Duplicate II
//Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> lastInd;
    const size_t size = nums.size();
    for(int i = 0;i<size;i++){
        if(lastInd.find(nums[i])!=lastInd.end() && std::abs(i - lastInd[nums[i]]) <= k)
            return true;
        lastInd[nums[i]] = i;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,0,1,1};
    int k = 1;
    std::cout<<containsNearbyDuplicate(nums, k)<<std::endl;
    
}
