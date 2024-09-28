#include <iostream>

// 58. Length of Last Word
// Given a string s consisting of words and spaces, return the length of the last word in the string.

int lengthOfLastWord(const std::string& str){
    bool isBeginingFound = false;
    int count = 0;
    const size_t size = str.length();
    for(int i = size - 1;i >= 0;i--){
        if(str[i] != ' '){
            isBeginingFound = true;
            count++;
        }
        else if(isBeginingFound)
            break;
    }
    return count;
}

int main(){
    std::string str = "  fly me   to   the moon  ";
    std::cout<<lengthOfLastWord(str)<<std::endl;
}
