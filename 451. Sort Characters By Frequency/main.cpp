#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>
#include <string>

// 451. Sort Characters By Frequency
// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string. Return the sorted string. If there are multiple answers, return any of them.

std::unordered_map<char, int> turnInMap(const std::string& str){
    
    std::unordered_map<char, int>map;
    for(const auto& ch : str){
        map[ch]++;
    }
    return map;
}

bool sortString(std::pair<char,int>& a,std::pair<char,int>& b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

std::string toString(std::vector<std::pair<char,int>>& v){
    std::string res;
    const size_t size = v.size();
    for(int i = 0;i<size;i++){
        res+=v[i].first;
    }
    return res;
}

std::string frequencySort(const std::string& str){
    std::unordered_map<char, int> map = turnInMap(str);
    std::vector<std::pair<char,int>> p(str.length());
    const size_t strSize = str.length();
    for(int i = 0;i<strSize;i++){
        p[i] = std::make_pair(str[i], map[str[i]]);
    }
    std::sort(p.begin(),p.end(),sortString);
    return toString(p);
}

int main(){
    std::string str = "tree";
    std::cout<<frequencySort(str)<<std::endl;
}
