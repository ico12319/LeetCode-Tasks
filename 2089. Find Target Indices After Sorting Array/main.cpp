#include <iostream>
#include <string>
#include <unordered_map>

//2089. Find Target Indices After Sorting Array
// You are given a 0-indexed integer array nums and a target element target.A target index is an index i such that nums[i] == target.Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

std::unordered_map<int, std::vector<int>> fillMap(std::vector<int>& nums){
    const size_t size = nums.size();
    std::sort(nums.begin(),nums.end());
    std::unordered_map<int, std::vector<int>> m;
    for(int i = 0;i<size;i++)
        m[nums[i]].push_back(i);
    return m;
}

std::vector<int> targetIndices(std::vector<int>& nums,int target){
    const size_t size = nums.size();
    std::unordered_map<int, std::vector<int>> m = fillMap(nums);
    
    if (m.find(target) != m.end()) {
        return m[target];
    }
    return {};
}

int main(int argc, const char * argv[]) {
    std::vector<int> arr = {1,2,5,2,3};
    std::vector<int> ind = targetIndices(arr, 3);
}
