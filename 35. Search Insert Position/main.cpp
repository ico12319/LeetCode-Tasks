#include <iostream>

//35. Search Insert Position
//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.You must write an algorithm with O(log n) runtime complexity.

int search(const std::vector<int>& nums,int target){
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return high + 1;
}

int main(int argc, const char * argv[]) {
    std::vector<int> nums = {1,3,5,6};
    std::cout<<search(nums, 7)<<std::endl;
}
