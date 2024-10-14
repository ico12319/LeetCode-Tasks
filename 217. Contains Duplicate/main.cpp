#include <iostream>
#include <unordered_set>

//217. Contains Duplicate
//Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct

bool containsDuplicate(std::vector<int>& nums){
    const size_t size = nums.size();
    std::unordered_set<int> seen;
    for(int i = 0;i<size;i++){
        if(seen.contains(nums[i]))
            return true;
        seen.insert(nums[i]);
    }
    return false;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,2,3,1};
    std::cout<<containsDuplicate(nums)<<std::endl;
}
