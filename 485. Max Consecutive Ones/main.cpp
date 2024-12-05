#include <iostream>
#include <unordered_set>

//485. Max Consecutive Ones
//Given a binary array nums, return the maximum number of consecutive 1's in the array.

size_t find_max_consecutive_ones(std::vector<int>& nums){
    size_t max_size = 0;
    size_t curr_size = 0;
    std::unordered_set<int> set;
    for(const auto& num : nums){
        set.insert(num);
        if(num && set.contains(num)){
            curr_size++;
            max_size = std::max(max_size,curr_size);
        }
        else
            curr_size = 0;
    }
    return max_size;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,1,0,1};
    std::cout<<find_max_consecutive_ones(nums)<<std::endl;
}
