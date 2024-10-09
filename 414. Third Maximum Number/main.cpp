#include <iostream>

//414. Third Maximum Number
//Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

bool cmp(int a,int b){
    return a > b;
}

int thirdMax(std::vector<int>& nums){
    std::sort(nums.begin(),nums.end(),cmp);
    int max = nums[0];
    int currMax = max;
    int counter = 0;
    const size_t size = nums.size();
    for(int i = 1;i<size;i++){
        if(currMax!=nums[i]){
            currMax = nums[i];
            counter++;
            if(counter == 2)
                return currMax;
        }
    }
    return max;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,2};
    std::cout<<thirdMax(nums)<<std::endl;
}
