#include <stdio.h>
#include <iostream>
#include <unordered_set>

//3. Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without repeating characters.

int lengthOfLongestSubstring(std::string& s){
    int start = 0;
    int index = 0;
    int max = 0;
    int size = s.length();
    std::unordered_set<char> unique;
    while(index < size){
        if(unique.contains(s[index])){
            unique.erase(s[start]);
            start++;
            continue;
        }
        unique.insert(s[index]);
        int currSize = unique.size();
        if(currSize > max)
            max = currSize;
        index++;
    }
    return max;
}

int main(){
    std::string str = "pwwkew";
    std::cout<<lengthOfLongestSubstring(str)<<std::endl;
}
