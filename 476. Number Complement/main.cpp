#include <iostream>

//476. Number Complement
// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
//For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
//Given an integer num, return its complement.

int determineBits(int& number){
    int bitsCount = 0;
    while(number > 0){
        bitsCount++;
        number >>= 1;
    }
    return bitsCount;
}

int findComplement(int num){
    int temp = num;
    int mask = 1;
    int bitsCount = determineBits(temp);
    for(int i = 0;i<bitsCount;i++){
        num ^= mask;
        mask<<=1;
    }
    return num;
}

int main(int argc, const char * argv[]) {
    int number = 5;
    std::cout<<findComplement(number)<<std::endl;
}
