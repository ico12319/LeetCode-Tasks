#include <iostream>

//283. Move Zeroes
//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.Note that you must do this in-place without making a copy of the array.can obtain.

void moveZeros(std::vector<int>& nums){
    const size_t size = nums.size();
    int lastNonZerEl = 0;
    for(int i = 0;i<size;i++){
        if(nums[i]!=0){
            std::swap(nums[i],nums[lastNonZerEl]);
            lastNonZerEl++;
        }
    }
}

void print(const std::vector<int>& v){
    const size_t size = v.size();
    for(int i = 0;i<size;i++){
        std::cout<<v[i]<<" ";
    }
}
int main(int argc, const char * argv[]) {
    std::vector<int> arr = {0,1,0,3,12};
    moveZeros(arr);
    print(arr);
}
