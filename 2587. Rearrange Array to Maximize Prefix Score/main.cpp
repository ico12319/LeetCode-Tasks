#include <iostream>

//2587. Rearrange Array to Maximize Prefix Score
//You are given a 0-indexed integer array nums. You can rearrange the elements of nums to any order (including the given order).Let prefix be the array containing the prefix sums of nums after rearranging it. In other words, prefix[i] is the sum of the elements from 0 to i in nums after rearranging it. The score of nums is the number of positive integers in the array prefix.Return the maximum score you can achieve.

int maxScore(std::vector<int>& nums) {
    const size_t size = nums.size();
    int maxScore = 0;
    long long currSum = 0;
    std::sort(nums.begin(),nums.end(),std::greater<int>());
    for(int i = 0;i<size;i++){
        currSum+=nums[i];
        if(currSum > 0)
            maxScore++;
        else
            break;
    }
    return maxScore;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
