#include <iostream>

//1464. Maximum Product of Two Elements in an Array
//Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).

int maxProduct(std::vector<int>& nums) {
    const size_t size = nums.size();
    std::sort(nums.begin(),nums.end(),std::greater<int>());
    return (nums[0] - 1) * (nums[1] - 1);
}

int main(int argc, const char * argv[]) {
    std::vector<int> v = {3,4,5};
    std::cout<<maxProduct(v)<<std::endl;
}
