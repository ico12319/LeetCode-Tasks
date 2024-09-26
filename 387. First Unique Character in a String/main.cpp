#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>

// 387. First Unique Character in a String
// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

std::unordered_map<char, int> turnInMap(const std::string& str){
    
    std::unordered_map<char, int>map;
    for(const auto& ch : str){
        map[ch]++;
    }
    return map;
}

int firstUniqChar(const std::string& str){
    const size_t strSize = str.size();
    std::unordered_map<char, int> map = turnInMap(str);
    for(int i = 0;i<strSize;i++){
        if(map[str[i]] == 1)
            return i;
    }
    return -1;
}

int main(){
    std::string str = "aabb";
    std::cout<<firstUniqChar(str)<<std::endl;
}
