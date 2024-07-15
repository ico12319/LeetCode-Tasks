#include <iostream>

// 231. Power of Two
// Given an integer n, return true if it is a power of two. Otherwise, return false.


bool isPowerOfTwo(int num){
    return num > 0 && (num & (num - 1)) == 0;
}

int main(int argc, const char * argv[]) {
   
    std::cout<<isPowerOfTwo(3)<<std::endl;
    std::cout<<isPowerOfTwo(8)<<std::endl;
}
