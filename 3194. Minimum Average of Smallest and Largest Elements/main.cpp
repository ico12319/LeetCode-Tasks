#include <iostream>

//3194. Minimum Average of Smallest and Largest Elements
//You have an array of floating point numbers averages which is initially empty. You are given an array nums of n integers where n is even.You repeat the following procedure n / 2 times:

double minimumAverage(std::vector<int>& nums){
    std::sort(nums.begin(),nums.end());
    int left = 0;
    double minAv = INT_MAX;
    int right = nums.size() - 1;
    while(left < right){
        double difference = (nums[left] + nums[right]) / 2.0;
        minAv = std::min(minAv,difference);
        left++;
        right--;
    }
    return minAv;
}

int main(int argc, const char * argv[]) {
    std::vector<int> v = {7,8,3,4,15,13,4,1};
    std::cout<<minimumAverage(v)<<std::endl;
}
