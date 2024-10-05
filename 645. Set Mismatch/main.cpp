#include <stdio.h>
#include <iostream>

//645. Set Mismatch
// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.Find the number that occurs twice and the number that is missing and return them in the form of an array.

bool binarySearch(std::vector<int>& nums,int target){
    const size_t size = nums.size();
    int left = 0;
    int right = size - 1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(nums[mid] == target)
            return true;
        else if(nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

std::vector<int> findErrorNums(std::vector<int>& nums) {
    const int size = nums.size();
    std::sort(nums.begin(),nums.end());
    int firstMissing = 1;
    int duplicate = -1;
    for(int i = 1;i<size;i++){
        if(nums[i] == nums[i - 1]){
            duplicate = nums[i];
            break;
        }
    }
    
    while(true){
        if(binarySearch(nums, firstMissing))
            firstMissing++;
        else
            break;
    }
    return std::vector<int>{duplicate,firstMissing};
    }

int main(){
    std::vector<int> nums = {1,2,2,4};
    std::vector<int> res = findErrorNums(nums);
    for(const auto& num : res)
        std::cout<<num<<" ";
}
