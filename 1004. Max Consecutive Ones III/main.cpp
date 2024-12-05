#include <iostream>

//1004. Max Consecutive Ones III
//Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

size_t longes_ones(std::vector<int>& nums,int k){
    std::unordered_map<size_t, size_t> freq;
    size_t max_size = 0;
    size_t left_ptr = 0;
    size_t right_ptr = 0;
    freq[nums[left_ptr]]++;
    
    while(true){
        size_t curr_window_size = (right_ptr - left_ptr) + 1;
        if(freq[0] == 0 || curr_window_size - freq[1] <= k){
            right_ptr++;
            freq[nums[right_ptr]]++;
            max_size = std::max(max_size, curr_window_size);
            if(right_ptr >= nums.size()) break;
        }
        else{
            freq[nums[left_ptr]]--;
            left_ptr++;
            if(left_ptr == right_ptr){
                right_ptr++;
                freq[nums[right_ptr]]++;
                if(right_ptr >= nums.size()) break;
            }
        }
    }
    return max_size;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {0,0,1,1};
    std::cout<<longes_ones(nums, 1)<<std::endl;
}
