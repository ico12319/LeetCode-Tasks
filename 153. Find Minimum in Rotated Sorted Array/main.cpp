#include <iostream>

//153. Find Minimum in Rotated Sorted Array
//Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:[4,5,6,7,0,1,2] if it was rotated 4 times.[0,1,2,4,5,6,7] if it was rotated 7 times.Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].Given the sorted rotated array nums of unique elements, return the minimum element of this array.

int search_min(const std::vector<int>& nums){
    int left = 0;
    int right = nums.size() - 1;
    int min = INT_MAX;
    while(left <= right){
        auto mid = (left + right) / 2;
        if(nums[left] <= nums[mid]){
            min = std::min(min, nums[left]);
            left = mid + 1;
        }
        else{
            min = std::min(min, nums[mid]);
            right = mid - 1;
        }
    }
    return min;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {4,5,6,0,1,2};
    std::cout<<search_min(nums)<<std::endl;
}
