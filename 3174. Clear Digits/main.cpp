#include <iostream>

//3174. Clear Digits
//You are given a string s.Your task is to remove all digits by doing this operation repeatedly:Delete the first digit and the closest non-digit character to its left.Return the resulting string after removing all digits.

std::string clearDigits(std::string& s){
    const size_t size = s.length();
    std::string res;
    for(int i = 0;i<size;i++){
        if(!std::isdigit(s[i])){
            res.push_back(s[i]);
        }
        else
            res.pop_back();
    }
    return res;
}

int main(int argc, const char * argv[]) {
    std::string s = "cb4t5";
    std::string res = clearDigits(s);
    std::cout<<res<<std::endl;
}
