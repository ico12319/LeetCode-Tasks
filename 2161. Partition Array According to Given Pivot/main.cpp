#include <iostream>

//2161. Partition Array According to Given Pivot
//You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:Every element less than pivot appears before every element greater than pivot.Every element equal to pivot appears in between the elements less than and greater than pivot.The relative order of the elements less than pivot and the elements greater than pivot is maintained.More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. For elements less than pivot, if i < j and nums[i] < pivot and nums[j] < pivot, then pi < pj. Similarly for elements greater than pivot, if i < j and nums[i] > pivot and nums[j] > pivot, then pi < pj.Return nums after the rearrangement.


std::vector<int> pivot_array(std::vector<int>& nums,int pivot){
    auto it = std::stable_partition(nums.begin(), nums.end(), [&pivot](int x){return x < pivot;});
    auto it2 = std::stable_partition(it, nums.end(), [&pivot](int x){return x == pivot;});
    if(it2 != nums.end())
        std::stable_partition(it2, nums.end(), [&pivot](int x){return x > pivot;});
    else
        std::stable_partition(it, nums.end(), [&pivot](int x){return x > pivot;});
    return nums;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {-3,4,3,2};
    int pivot = 2;
    auto partitioned = pivot_array(nums, pivot);
    for(const auto& el : partitioned)
        std::cout<<el<<" ";
}
