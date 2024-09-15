#include <iostream>

// 1047. Remove All Adjacent Duplicates In String

// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
// We repeatedly make duplicate removals on s until we no longer can.
//Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

std::string removeDupilcates(const std::string& s){
    std::string result;
    size_t index = 0;
    size_t size = s.length();
    
    while(index < size){
        if(result.empty() || s[index] != result.back())
            result.push_back(s[index]);
        else
            result.pop_back();
        index++;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::string str = "abbaca";
    std::string res = removeDupilcates(str);
    std::cout<<res<<std::endl;
}
