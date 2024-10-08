#include <iostream>
#include <string>
#include <unordered_map>

//747. Largest Number At Least Twice of Others
// You are given an integer array nums where the largest integer is unique.Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwis

bool cmp(int num1,int num2){
    return num1 > num2;
}


std::unordered_map<int, int> fillMap(std::vector<int>& nums){
    std::unordered_map<int, int> m;
    std::sort(nums.begin(),nums.end(),cmp);
   
    for(int i = 1;i<nums.size();i++){
        m[nums[i]]++;
    }
    return m;
}

int findMaxIndex(const std::vector<int>& nums){
    const size_t size = nums.size();
    int max = nums[0];
    int maxIndex = 0;
    for(int i = 1;i<size;i++){
        if(max < nums[i]){
            max = nums[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

int dominantIndex(std::vector<int>& nums){
    const size_t size = nums.size();
    int maxIndex = findMaxIndex(nums);
    std::unordered_map<int, int> m = fillMap(nums);
    int max = nums[0];
    for(const auto& pair: m){
        if(max < pair.first * 2)
            return -1;
    }
    return maxIndex;
}


int main(int argc, const char * argv[]) {
    std::vector<int> arr = {1,0};
    std::cout<<dominantIndex(arr)<<std::endl;
}
