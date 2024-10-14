#include <iostream>

//1502. Can Make Arithmetic Progression From Sequence
//A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

bool canMakeArithmeticProgression(std::vector<int>& arr) {
    const size_t size = arr.size();
    std::sort(arr.begin(),arr.end());
    int d = arr[0] - arr[1];
    for(int i = 0;i<size-1;i++){
        if(arr[i] - arr[i+1]!=d)
            return false;
    }
    return true;
}


int main(int argc, const char * argv[]) {
    std::vector<int> v = {1,2,4};
    std::cout<<canMakeArithmeticProgression(v)<<std::endl;
}
