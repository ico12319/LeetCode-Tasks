#include <iostream>
#include <fstream>
#include <vector>

//728. Self Dividing Numbers
// A self-dividing number is a number that is divisible by every digit it contains.

int digitsCount(int num){
    if(num == 0)
        return 1;
    
    int count = 0;
    while(num != 0){
        count++;
        num/=10;
    }
    return count;
}

bool isSelfDividing(int num){
    int digits = digitsCount(num);
    if(digits == 1)
        return true;
    
    int count = 0;
    int originalNum = num;
    while(num != 0){
        int digit = num % 10;
        if(digit != 0){
            if(originalNum % digit == 0)
                count++;
        }
        num /= 10;
    }
    return count == digits;
}

std::vector<int> selfDividingNumbers(int left,int right){
    std::vector<int> numbers;
    for(int i = left;i<=right;i++){
        if(isSelfDividing(i))
            numbers.push_back(i);
    }
    return numbers;
}

int main(int argc, const char * argv[]) {
    int left = 47;
    int right = 85;
    std::vector<int> nums = selfDividingNumbers(left, right);
}
