#include <iostream>

//88. Merge Sorted Array
//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.Merge nums1 and nums2 into a single array sorted in non-decreasing order.

void mergeSorted(std::vector<int>& arr1,size_t size1,std::vector<int>& arr2,size_t size2){
    if(arr1.empty())
        arr1 = arr2;
    if(arr2.empty())
        return;
    
    int i = size1 - 1;
    int j = size2 - 1;
    int k = size1 + size2 - 1;
    while(i>=0 && j>=0){
        if(arr1[i] > arr2[j]){
            arr1[k] = arr1[i];
            i--;
        }
        else{
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }
    while(j >= 0){
        arr1[k] = arr2[j];
        j--;
        k--;
    }
}

void print(const std::vector<int>& arr,size_t size){
    for(int i = 0;i<size;i++)
        std::cout<<arr[i]<<" ";
}

int main(int argc, const char * argv[]) {
    std::vector<int> v1 = {1};
    std::vector<int> v2 = {};
    mergeSorted(v1, 1, v2, 0);
    print(v1, 1);
}
