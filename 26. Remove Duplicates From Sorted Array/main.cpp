#include <iostream>
#include <map>

//26. Remove Duplicates from Sorted Array
//Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

std::map<int, int> fillMap(const std::vector<int>& v){
    std::map<int, int> m;
    for(const auto& num : v)
        m[num]++;
    return m;
}
size_t removeDuplicates(std::vector<int>& nums){
    std::map<int, int> m = fillMap(nums);
    nums.clear();
    for(const auto& pair : m)
        nums.push_back(pair.first);
    return nums.size();
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    std::cout<<removeDuplicates(nums)<<std::endl;

}
