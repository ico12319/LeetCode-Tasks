#include <iostream>

//2971. Find Polygon With the Largest Perimeter
//You are given an array of positive integers nums of length n.A polygon is a closed plane figure that has at least 3 sides. The longest side of a polygon is smaller than the sum of its other sides.
//Return the largest possible perimeter of a polygon whose sides can be formed from nums, or -1 if it is not possible to create a polygon.

long long largestPerimeter(std::vector<int>& nums) {
    const size_t size = nums.size();
    std::sort(nums.begin(),nums.end());
    long long sum = 0;
    long long maxPer = INT_MIN;
    sum+=nums[0];
    for(int i = 1;i<size;i++){
        if(nums[i] < sum){
            sum+=nums[i];
            maxPer = std::max(maxPer,sum);
        }
        else
            sum+=nums[i];
    }
    if(maxPer == INT_MIN)
        return -1;
    return maxPer;
}


int main(int argc, const char * argv[]) {
    std::vector<int> nums = {5,5,5};
    std::cout<<largestPerimeter(nums)<<std::endl;
}
