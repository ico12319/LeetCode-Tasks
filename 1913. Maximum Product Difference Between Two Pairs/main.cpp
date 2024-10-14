#include <stdio.h>
#include <iostream>

//1913. Maximum Product Difference Between Two Pairs
//The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.Return the maximum such product difference.


int maxProductDifference(std::vector<int>& nums){
    const size_t size = nums.size();
    std::sort(nums.begin(),nums.end(),std::greater<int>());
    return nums[0] * nums[1] - nums[size - 1] * nums[size - 2];
}

int main(){
    std::vector<int> v = {5,6,2,7,4};
    std::cout<<maxProductDifference(v)<<std::endl;
}
