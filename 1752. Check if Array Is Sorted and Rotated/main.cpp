#include <iostream>

bool check_if_sorted_and_rotated(const std::vector<int>& nums){
    int count = 0;
    for(int i = 1; i<nums.size();i++){
        if(nums[i] < nums[i - 1]){
            count++;
            if(count > 1)
                return false;
        }
    }
    if(count == 1 && nums[nums.size() - 1] > nums[0])
        return false;
    return true;
    
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {3,6,10,1,8,9,9,8,9};
    std::cout<<check_if_sorted_and_rotated(nums)<<std::endl;
}
