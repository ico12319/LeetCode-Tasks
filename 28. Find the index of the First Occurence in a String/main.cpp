#include <iostream>
#include <stack>

// 28. Find the Index of the First Occurrence in a String
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


bool isPrefix(const std::string& str1, const std::string& str2, size_t pos1 = 0, size_t pos2 = 0) {
    if (pos2 == str2.size())
        return true;
    if (pos1 == str1.size() || str1[pos1] != str2[pos2])
        return false;
    return isPrefix(str1, str2, pos1 + 1, pos2 + 1);
}

int findInTextRec(const std::string& text, const std::string& pattern, int currentIndex) {
    if (pattern.size() > text.size() - currentIndex)
        return -1;

    if (isPrefix(text, pattern, currentIndex))
        return currentIndex;

    return findInTextRec(text, pattern, currentIndex + 1);
}

int findInText(const std::string& hayStack, const std::string& needle)
{
    return findInTextRec(hayStack, needle, 0);
}

int main(int argc, const char * argv[]) {
   
    std::string str1 = "mississippi";
    std::string str2 = "issip";
    std::cout<<findInText(str1, str2)<<std::endl;
    
}
