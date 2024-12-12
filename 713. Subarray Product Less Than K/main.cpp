#include <iostream>

//713. Subarray Product Less Than K
//Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    size_t left_ptr = 0;
    size_t right_ptr = 0;
    size_t curr_product = 1;
    size_t count = 0;
    while(true){
        curr_product*=nums[right_ptr];
        if(curr_product < k){
            count++;
            right_ptr++;
            if(right_ptr >= nums.size()){
                left_ptr++;
                curr_product = 1;
                if(left_ptr >= nums.size()) break;
                right_ptr = left_ptr;
            }
        }
        else if(curr_product >= k){
            left_ptr++;
            curr_product = 1;
            if(left_ptr >= nums.size()) break;
            right_ptr = left_ptr;
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,2,3};
    int k = 0;
    std::cout<<numSubarrayProductLessThanK(nums, k)<<std::endl;
}
