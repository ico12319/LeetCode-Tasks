#include <iostream>

// 392. Is Subsequence
// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

bool isSusequence(std::string& str1,std::string& str2){
    const size_t str1Size = str1.length();
    const size_t str2Size = str2.length();
    int targetPointer = 0;
    int count = 0;
    for(int i = 0;i<str2Size;i++){
        if(str1[targetPointer] == str2[i]){
            count++;
            targetPointer++;
        }
    }
    return count == str1Size;
}



int main(int argc, const char * argv[]) {
    
    std::string str1 = "axc";
    std::string str2 = "ahbgdc";
    std::cout<<isSusequence(str1, str2)<<std::endl;
}
