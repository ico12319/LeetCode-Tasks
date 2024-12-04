#include <iostream>

//594. Longest Harmonious Subsequence
//We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.Given an integer array nums, return the length of its longest harmonioussubsequence among all its possible subsequences.



int find_longest_harmonious_subsequence(std::vector<int>& nums){
    std::unordered_map<int,int> map;
    for(const auto& el : nums)
        map[el]++;
    
    int max = 0;
    for(int i = 0;i<nums.size();i++){
        if(map.contains(nums[i] + 1))
            max = std::max(max,map[nums[i]] + map[nums[i] + 1]);
    }
    return max;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,3,2,2,5,2,3,7};
    std::cout<<find_longest_harmonious_subsequence(nums)<<std::endl;
}
