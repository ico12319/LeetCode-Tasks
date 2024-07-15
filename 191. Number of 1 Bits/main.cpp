#include <iostream>

// 191. Number of 1 Bits
// Write a function that takes the binary representation of a positive integer and returns the number of
//set bits it has (also known as the Hamming weight).


int hammingWeight(int number){ // 0 ms
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
