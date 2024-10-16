#include <iostream>

//349. Intersection of Two Arrays
//Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
         const size_t size = nums1.size();
    std::vector<int> intersect;
    int lastNumAdded = INT_MAX;
    std::sort(nums1.begin(),nums1.end());
    std::sort(nums2.begin(),nums2.end());
    for(int i = 0;i<size;i++){
        if((std::binary_search(nums2.begin(), nums2.end(), nums1[i])) && lastNumAdded!=nums1[i]){
            lastNumAdded = nums1[i];
            intersect.push_back(nums1[i]);
        }
    }
    return intersect;
    }

int main(int argc, const char * argv[]) {
    std::vector<int> nums1 = {1,2,4,5};
    std::vector<int> nums2 = {2,5,12};
    std::vector<int> inter = intersection(nums1, nums2);
    for(const auto& el : inter)
        std::cout<<el<<" ";
}
