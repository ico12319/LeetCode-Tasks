#include <iostream>
#include <fstream>

// 2520. Count the Digits That Divide a Number
// Given an integer num, return the number of digits in num that divide num.

int countDigits(int num){
    if(num == 1)
        return 1;
    
    int count = 0;
    int originalNum = num;
    while(num != 0){
        int digit = num % 10;
        if(originalNum % digit == 0)
            count++;
        num /= 10;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    std::cout<<countDigits(1248)<<std::endl;
    std::cout<<countDigits(121)<<std::endl;
    std::cout<<countDigits(7)<<std::endl;
}
