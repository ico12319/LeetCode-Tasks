#include <iostream>

//167. Two Sum II - Input Array Is Sorted
//Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

int binarySearch(const std::vector<int>& numbers,int target,int start){
    int left = start;
    int right = numbers.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(numbers[mid] == target)
            return mid;
        else if(numbers[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

std::vector<int> twoSum(std::vector<int>& numbers,int target){
    const size_t size = numbers.size();
    int start = 0;
    for(int i = 0;i<size;i++){
        int targetIndex = binarySearch(numbers, target - numbers[i],start+i+1);
        if(targetIndex!=-1)
            return std::vector<int>{i+1,targetIndex + 1};
    }
    return {};
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,2,3,4,4,9,56,90};
    int target = 8;
    std::vector<int> indicies = twoSum(nums, target);
}
