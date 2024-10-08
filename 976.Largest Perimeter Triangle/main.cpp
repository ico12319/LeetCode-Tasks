#include <iostream>

//976. Largest Perimeter Triangle
//Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

bool cmp(int a,int b){
    return a > b;
}

int largestPermieter(std::vector<int>& nums){
    const size_t size = nums.size();
    std::sort(nums.begin(),nums.end(),cmp);
    for(int i = 0;i<size - 2;i++){
        if(nums[i] < nums[i+1] + nums[i+2])
            return nums[i] + nums[i+1] + nums[i+2];
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    std::vector<int> arr = {2,1,2};
    std::cout<<largestPermieter(arr)<<std::endl;
}
