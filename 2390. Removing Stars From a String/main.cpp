#include <iostream>

//2390. Removing Stars From a String
//You are given a string s, which contains stars *.
//In one operation, you can:
//Choose a star in s.
//Remove the closest non-star character to its left, as well as remove the star itself.
//Return the string after all stars have been removed.


std::string removeStars(const std::string& s){
    std::string res;
    int index = 0;
    size_t size = s.length();
    while(index < size){
        if(res.empty() || s[index] != '*')
            res.push_back(s[index]);
        else
            res.pop_back();
        index++;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    std::string str = "leet**cod*e";
    std::string result = removeStars(str);
    std::cout<<result<<std::endl;
}
