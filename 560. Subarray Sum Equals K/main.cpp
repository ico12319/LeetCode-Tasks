#include <iostream>

size_t subarray_sum(const std::vector<int>& nums,int k){
    int curr_sum = 0;
    size_t count = 0;
    std::unordered_map<int,int> prefix_sums_count;
    prefix_sums_count[0] = 1;
    for(const auto& num : nums){
        curr_sum+=num;
        int diff = curr_sum - k;
        if(prefix_sums_count.contains(diff))
            count+=prefix_sums_count[diff];
        prefix_sums_count[curr_sum]++;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,-1,0};
    int k = 0;
    std::cout<<subarray_sum(nums, k)<<std::endl;
}
