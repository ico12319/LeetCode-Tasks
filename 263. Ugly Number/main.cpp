#include <iostream>
#include <fstream>

// 263. Ugly Number
// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
//Given an integer n, return true if n is an ugly number.

int divideByTwo(int n){
    while(n % 2 == 0)
        n /= 2;
    return n;
}

int divideByThree(int n){
    while(n % 3 == 0)
        n /= 3;
    return n;
}

int divideByFive(int n){
    while(n % 5 == 0)
        n /= 5;
    return n;
}

bool isUgly(int n){
    if(n == 1)
        return true;
    if(n == 0)
        return false;
    
    n = divideByTwo(n);
    n = divideByThree(n);
    n = divideByFive(n);
    if(n == 1)
        return true;
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    std::cout<<isUgly(6)<<std::endl;
    std::cout<<isUgly(1)<<std::endl;
    std::cout<<isUgly(15)<<std::endl;
    
}
