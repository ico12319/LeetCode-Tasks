#include <iostream>
#include <unordered_set>

//448. Find All Numbers Disappeared in an Array
//Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    std::unordered_set<int> set;
    for(const auto& el : nums)
        set.insert(el);
    
    std::vector<int> res;
    for(int i = 1;i<=nums.size();i++){
        if(!set.contains(i))
            res.push_back(i);
    }
    return res;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
