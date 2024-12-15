#include <iostream>

//53. Maximum Subarray
//Given an integer array nums, find the subarray with the largest sum, and return its sum.

int max_sub_array(const std::vector<int>& nums){
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for(int i = 0;i<nums.size();i++){
        curr_sum+=nums[i];
        max_sum = std::max(max_sum, curr_sum);
        if(curr_sum < 0)
            curr_sum = 0;
    }
    return max_sum;
}


int main(int argc, const char * argv[]) {
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout<<max_sub_array(nums)<<std::endl;
}
