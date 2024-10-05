#include <iostream>

//189. Rotate Array
//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

void reverse(std::vector<int>& nums,int start,int end){
    while(start < end){
        std::swap(nums[start],nums[end]);
        start++;
        end--;
    }
}


void rotate(std::vector<int>& nums,int k){
    const size_t size = nums.size();
    k = k % size;
    reverse(nums, 0, size - k - 1);
    reverse(nums, size - k, size - 1);
    reverse(nums, 0, size - 1);
}

void print(const std::vector<int>& nums){
    const size_t size = nums.size();
    for(int i = 0;i<size;i++)
        std::cout<<nums[i]<<" ";
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,5,6,8};
    int k = 2;
    rotate(nums, 2);
    print(nums);
}
