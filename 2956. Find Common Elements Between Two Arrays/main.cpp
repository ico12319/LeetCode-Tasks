#include <iostream>
#include <unordered_set>

//2956. Find Common Elements Between Two Arrays
//You are given two integer arrays nums1 and nums2 of sizes n and m, respectively. Calculate the following values: answer1 : the number of indices i such that nums1[i] exists in nums2. answer2 : the number of indices i such that nums2[i] exists in nums1.Return [answer1,answer2].

std::vector<int> find_intersection_values(std::vector<int>& nums1,std::vector<int>& nums2){
    std::unordered_set<int> set1(nums1.begin(),nums1.end());
    std::unordered_set<int> set2(nums2.begin(),nums2.end());
    std::vector<int> res;
    auto matches = 0;
    for(const auto& num : nums1){
        if(set2.contains(num))
            matches++;
    }
    res.push_back(matches);
    auto matches2 = 0;
    for(const auto& num : nums2){
        if(set1.contains(num))
            matches2++;
    }
    res.push_back(matches2);
    return res;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
