#include <iostream>

//1662. Check If Two String Arrays are Equivalent
// Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

//A string is represented by an array if the array elements concatenated in order forms the string.

bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
    std::string c1,c2;
    for(const auto& ch : word1)
        c1+=ch;
    for(const auto& ch : word2)
        c2+=ch;
    return c1 == c2;
}

int main(int argc, const char * argv[]) {
    std::vector<std::string> v1 = {"ab", "c"};
    std::vector<std::string> v2 = {"a","bc"};
    std::cout<<arrayStringsAreEqual(v1, v2)<<std::endl;
}
