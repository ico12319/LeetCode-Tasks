#include <iostream>

//205. Isomorphic Strings
//Given two strings s and t, determine if they are isomorphic.Two strings s and t are isomorphic if the characters in s can be replaced to get t.All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

bool is_isomoprhic(std::string& str1,std::string& str2){
    if(str1.size() != str2.size()) return false;
    const int size = str1.length();
    std::unordered_map<char, char> map1;
    std::unordered_map<char, char> map2;
    for(int i = 0;i<size;i++){
        if(map1.find(str1[i]) != map1.end() && map1[str1[i]] != str2[i] || map2.find(str2[i]) != map2.end() && map2[str2[i]] != str1[i])
            return false;
        map1[str1[i]] = str2[i];
        map2[str2[i]] = str1[i];
    }
    return true;
}

int main(int argc, const char * argv[]) {
    std::string str1 = "egg";
    std::string str2 = "add";
   
    std::cout<<is_isomoprhic(str1, str2)<<std::endl;
}
