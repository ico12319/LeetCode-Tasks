#include <iostream>

//164. Maximum Gap
//Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.You must write an algorithm that runs in linear time and uses linear extra space.

int maximumGap(std::vector<int>& nums){
    const size_t size = nums.size();
    if(size < 2)
        return 0;
    std::sort(nums.begin(),nums.end(),std::greater<>());
    int maxGap = nums[0] - nums[1];
    for(int i = 0;i<size-1;i++){
        int currGap = nums[i] - nums[i+1];
        if(currGap>maxGap)
            maxGap = currGap;
    }
    return maxGap;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {3,6,9,1};
    std::cout<<maximumGap(nums)<<std::endl;
}
