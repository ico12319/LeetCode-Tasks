#include <iostream>

//34. Find First and Last Position of Element in Sorted Array
//Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.If target is not found in the array, return [-1, -1].You must write an algorithm with O(log n) runtime complexity.


std::vector<int> binarySearch(std::vector<int>& nums,int target){
    int left = 0;
    std::vector<int> ind;
    int right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            int temp =mid;
            while(temp >= left && nums[temp] == target){
                ind.insert(ind.begin(),temp);
                temp--;
            }
            
            temp = mid + 1;
            while(temp <= right && nums[temp] == target){
                ind.push_back(temp);
                temp++;
            }
            break;
        }
        else if(nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return ind;
}

std::vector<int> searchRange(std::vector<int>& nums,int target){
    const size_t size = nums.size();
    std::vector<int> ind = binarySearch(nums, target);
    size_t occurs = ind.size();
    if(occurs == 0 || nums.size() == 0)
        return {-1,-1};
    if(occurs == 1)
        return {ind[0],ind[0]};

    return {ind[0],ind[occurs - 1]};
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    std::vector<int> ind = searchRange(nums, target);
    for(const auto& el : ind)
        std::cout<<el<<" ";
}
