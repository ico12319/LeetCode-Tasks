#include <iostream>

//3194. Minimum Average of Smallest and Largest Elements
//You have an array of floating point numbers averages which is initially empty. You are given an array nums of n integers where n is even.You repeat the following procedure n / 2 times: Remove the smallest element, minElement, and the largest element maxElement, from nums.Add (minElement + maxElement) / 2 to averages.Return the minimum element in averages.

double minimumAverage(std::vector<int>& nums) {
    const size_t size = nums.size();
    std::sort(nums.begin(),nums.end());
    int leftPointer = 0;
    int rightPointer = nums.size() - 1;
    double minAverage = __DBL_MAX__;
    while(leftPointer < rightPointer){
        auto average = (nums[leftPointer] + nums[rightPointer]) / 2.0;
        minAverage = std::min(minAverage,average);
        leftPointer++;
        rightPointer--;
    }
    return minAverage;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {7,8,3,4,15,13,4,1};
    std::cout<<minimumAverage(nums)<<std::endl;
}
