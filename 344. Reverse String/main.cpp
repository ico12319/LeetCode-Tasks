#include <iostream>

//344. Reverse String
//Write a function that reverses a string. The input string is given as an array of characters s.You must do this by modifying the input array in-place with O(1) extra memory.

void reverseString(std::vector<char>& s){
    int half_size = s.size() / 2;
    for(int i = 0;i< half_size;i++)
        std::swap(s[i],s[s.size() - i - 1]);
}

int main(int argc, const char * argv[]) {
    std::vector<char> s = {'e','v','a'};
    reverseString(s);
    for(const auto& el : s)
        std::cout<<el<<" ";
}
