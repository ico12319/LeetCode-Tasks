#include <iostream>
#include <unordered_set>

//2215. Find the Difference of Two Arrays
//Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:answer[0] is a list of all distinct integers in nums1 which are not present in nums2 answer[1] is a list of all distinct integers in nums2 which are not present in nums1.Note that the integers in the lists may be returned in any order.

std::vector<std::vector<int>> find_difference(std::vector<int>& nums1,std::vector<int>& nums2){
    std::unordered_set<int> set1(nums1.begin(),nums1.end());
    std::unordered_set<int> set2(nums2.begin(),nums2.end());
    
    std::vector<int> only_in_first;
    for(const auto& el : set1){
        if(!set2.contains(el))
            only_in_first.push_back(el);
    }
    std::vector<int> only_in_second;
    for(const auto& el : set2){
        if(!set1.contains(el))
            only_in_second.push_back(el);
    }
    
    return {only_in_first,only_in_second};
}


int main(int argc, const char * argv[]) {
    std::vector<int> nums1 = {1,2,3};
    std::vector<int> nums2 = {2,4,6};
    auto res = find_difference(nums1, nums2);
    for(const auto& arr : res){
        for(const auto& el : arr)
            std::cout<<el<<" ";
        std::cout<<std::endl;
    }
}
