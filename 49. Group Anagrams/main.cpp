#include <iostream>
#include <unordered_map>

// 49. Group Anagrams
//Given an array of strings strs, group the anagrams together. You can return the answer in any order.

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& arr){
    std::unordered_map<std::string,std::vector<std::string>> anagramMap;
    for(const auto& word:arr){
        std::string sortedWord = word;
        std::sort(sortedWord.begin(),sortedWord.end());
        anagramMap[sortedWord].push_back(word);
    }
    std::vector<std::vector<std::string>> result;
    for(const auto& group : anagramMap){
        result.push_back(group.second);
    }
    return result;
}

void print(std::vector<std::vector<std::string>>& arr){
    for(const auto& group : arr){
        for(const auto& word : group)
            std::cout<<word<<" ";
        std::cout<<std::endl;
    }
}

int main(){
    std::vector<std::string> v = {"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> res = groupAnagrams(v);
    
    print(res);
}
