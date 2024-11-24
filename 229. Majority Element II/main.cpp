#include <iostream>
#include <unordered_map>

//229. Majority Element II
//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

std::vector<int> majorityElement(std::vector<int>& nums) {
    std::unordered_map<int, int> map;
    std::vector<int> res;
    int wanted_ocurr = nums.size() / 3;
    for(int i = 0;i<nums.size();i++){
        map[nums[i]]++;
        if(map[nums[i]] > wanted_ocurr && std::find(res.begin(), res.end(), nums[i]) == res.end())
            res.push_back(nums[i]);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    std::vector<int> v = {1,1,2,2,7,7,8,8,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3,9,3};
    std::vector<int> res = majorityElement(v);
    for(const auto& el : res)
        std::cout<<el<<" ";
}
