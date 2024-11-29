#include <iostream>

//3046. Split the Array
//You are given an integer array nums of even length. You have to split the array into two parts nums1 and nums2 such that: nums1.length == nums2.length == nums.length / 2. nums1 should contain distinct elements.nums2 should also contain distinct elements.Return true if it is possible to split the array, and false otherwise.

bool can_be_splitted(const std::vector<int>& nums){
    if(nums.size() == 0 || nums.size() == 1) return 0;
    std::unordered_map<int, int> map;
    for(const auto& num : nums){
        map[num]++;
        if(map[num] > 2)
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    std::vector<int> v {1,1,1,1,1,1};
    std::cout<<can_be_splitted(v)<<std::endl;
    
}
