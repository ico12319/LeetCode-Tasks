#include <iostream>

//496. Next Greater Element I
//The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.Return an array ans of length nums1.length such that ans[i] is the next greater element as described above

std::vector<int> next_greater_element(const std::vector<int>& nums1,const std::vector<int>& nums2){
    std::unordered_map<int, int> nums_ind;
    for(int i = 0;i<nums2.size();i++)
        nums_ind[nums2[i]] = i;
    
    std::vector<int> result;
    for(int i = 0;i<nums1.size();i++){
        auto index_in_second_arr = nums_ind.find(nums1[i]);
        bool found_bigger = false;
        for(int j = index_in_second_arr->second;j<nums2.size();j++){
            if(nums2[j] > index_in_second_arr->first){
                found_bigger = true;
                result.push_back(nums2[j]);
                break;
            }
        }
        if(!found_bigger)
            result.push_back(-1);
    }
    return result;
        
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums1 = {2,4};
    std::vector<int> nums2 = {1,2,3,4};
    auto next_greater = next_greater_element( nums1, nums2);
    for(const auto& el : next_greater)
        std::cout<<el<<std::endl;
}
