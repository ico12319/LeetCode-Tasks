#include <iostream>
#include <map>

//268. Missing Number
//Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

int missingNumber(std::vector<int>& nums){
    const size_t max = nums.size();
    if(nums[0] == 0 && max == 1)
        return 1;
    if(max == 1)
        return 0;
    
    int sumInterval = (max*(max + 1)) / 2;
    for(int i = 0;i<max;i++)
        sumInterval -= nums[i];
    return sumInterval;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {0,1};
    std::cout<<missingNumber(nums)<<std::endl;
}
