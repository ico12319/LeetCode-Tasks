#include <iostream>


int search(std::vector<int>& nums,int target){
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
