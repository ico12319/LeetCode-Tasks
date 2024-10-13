#include <iostream>
//680. Valid Palindrome II
//Given a string s, return true if the s can be palindrome after deleting at most one character from it.

bool isPalidrome(const std::string& str,int left,int right){
    while(left < right){
        if(str[left] == str[right]){
            left++;
            right--;
        }
        else
            return false;
    }
    return true;
}

bool validPalindrome(const std::string& s){
    int left = 0;
    int right = s.length() - 1;
    while(left < right){
        if(s[left] == s[right]){
            left++;
            right--;
        }
        else
            return isPalidrome(s, left + 1, right) || isPalidrome(s, left, right - 1);
    }
    return true;
}

int main(int argc, const char * argv[]) {
    std::string str = "caba";
    std::cout<<validPalindrome(str)<<std::endl;
}
