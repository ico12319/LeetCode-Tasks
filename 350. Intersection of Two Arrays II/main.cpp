#include <iostream>

//350. Intersection of Two Arrays II
//Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::sort(nums1.begin(),nums1.end());
    std::sort(nums2.begin(),nums2.end());
    std::vector<int> res;
    
    int left = 0;
    int right = 0;
    while(left!=nums1.size() && right!=nums2.size()){
        if(nums1[left] == nums2[right]){
            res.push_back(nums1[left]);
            left++;
            right++;
        }
        else if(nums1[left] > nums2[right])
            right++;
        else
            left++;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums1 = {1,2,2,1};
    std::vector<int> nums2 = {2,2};
    std::vector<int> res = intersect(nums1, nums2);
    for(const auto& el : res)
        std::cout<<el<<" ";
}
