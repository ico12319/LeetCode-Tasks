#include <iostream>

//1460. Make Two Arrays Equal by Reversing Subarrays
//You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.Return true if you can make arr equal to target or false otherwise.

constexpr size_t MIN_VALUE = 1;
constexpr size_t MAX_VALUE = 1000;
std::vector<int> countingSort(std::vector<int>& arr){
    std::vector<int> count(MAX_VALUE - MIN_VALUE + 1,0);
    for(int i = 0;i<arr.size();i++)
        count[arr[i] - MIN_VALUE]++;
    for(int i = 1;i<MAX_VALUE-MIN_VALUE+1;i++)
        count[i] += count[i - 1];
    std::vector<int> res(MAX_VALUE - MIN_VALUE + 1,0);
    for(int i = 0;i<arr.size();i++){
        size_t correctIndex = --count[arr[i] - MIN_VALUE];
        res[correctIndex] = arr[i];
    }
    return res;
}

bool canBeEqual(std::vector<int>& target,std::vector<int>& arr){
    if(target.size() != arr.size())
        return false;
    target = countingSort(target);
    arr = countingSort(arr);
    return target == arr;
}

int main(int argc, const char * argv[]) {
    std::vector<int> target = {1,2,3,4};
    std::vector<int> arr = {2,4,1,3};
    std::cout<<canBeEqual(target, arr)<<std::endl;
}
