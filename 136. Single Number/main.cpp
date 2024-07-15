#include <iostream>

// 136. Single Number
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.


int singleNumber(const std::vector<int>& nums){
    int res = 0;
    size_t size = nums.size();
    for(int i = 0;i<size;i++){
        res ^= nums[i];
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    std::cout<<singleNumber(nums)<<std::endl;
}
