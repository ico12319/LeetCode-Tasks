#include <iostream>

// 231. Power of Two
// Given an integer n, return true if it is a power of two. Otherwise, return false.


int hammingWeight(int number){
    int count = 0;
    int mask = 1;
    for(int i = 0;i<32;i++){
        if((number & mask) != 0)
            count++;
        mask = mask << 1;
    }
    return count;
}


int main(int argc, const char * argv[]) {
   
    std::cout<<hammingWeight(3)<<std::endl;
}
