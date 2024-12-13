#include <iostream>
#include <unordered_set>

//2540. Minimum Common Value
//Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

int get_common(std::vector<int>& nums1,std::vector<int>& nums2){
    std::unordered_set<int> seen1(nums1.begin(),nums1.end());
    std::unordered_set<int> seen2(nums2.begin(),nums2.end());
    for(int i = 0;i<nums1.size();i++){
        if(seen1.contains(nums1[i]) && seen2.contains(nums1[i]))
            return nums1[i];
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums1 = {1,2,3,6};
    std::vector<int> nums2 = {2,3,4,5};
    std::cout<<get_common(nums1, nums2)<<std::endl;
}
