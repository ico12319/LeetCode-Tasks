#include <iostream>
// 66. Plus One
//You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.Increment the large integer by one and return the resulting array of digits.


std::vector<int> plusOne(std::vector<int>& digits){
    const size_t size = digits.size();
    for(int i = size - 1;i>=0;i--){
        if(digits[i] < 9){
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

void print(const std::vector<int>& v){
    const size_t size = v.size();
    for(int i = 0;i<size;i++)
        std::cout<<v[i];
    std::cout<<std::endl;
}

int main(int argc, const char * argv[]) {
    std::vector<int> digits = {9,9,9};
    std::vector<int> res = plusOne(digits);
    print(res);
}
