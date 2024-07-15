#include <iostream>

// 242.Valid Anagram
//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

constexpr size_t ALPHABET_SIZE = 26;

bool isAnagram(std::string str1,std::string str2){
    int count[ALPHABET_SIZE] = {0};
    size_t sizeStr1 = str1.length();
    for(int i = 0;i<sizeStr1;i++){
        count[str1[i] - 'a']++;
    }
    
    size_t sizeStr2 = str2.length();
    for(int i = 0;i<sizeStr2;i++){
        count[str2[i] - 'a']--;
    }
    
    for(int i = 0;i<ALPHABET_SIZE;i++){
        if(count[i] != 0)
            return false;
    }
    return true;
}


int main(int argc, const char * argv[]) {
    
    std::string str1 = "car";
    std::string str2 = "rat";
    std::cout<<isAnagram(str1, str2)<<std::endl; // testcase 1
    
    std::string str3 = "anagram";
    std::string str4 = "nagaram";
    std::cout<<isAnagram(str3, str4)<<std::endl; // testcase 2
    
    
}
