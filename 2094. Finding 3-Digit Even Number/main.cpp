#include <iostream>
#include <unordered_map>

//2085. Count Common Words With One Occurrence
//Given two string arrays words1 and words2, return the number of strings that appear exactly once in each of the two arrays.

std::unordered_map<std::string,int> fillMap(const std::vector<std::string>& words){
    std::unordered_map<std::string, int> map;
    for(const auto& word : words){
        map[word]++;
    }
    return map;
}

int countWords(std::vector<std::string>& words1,std::vector<std::string>& words2){
    std::unordered_map<std::string, int> map = fillMap(words1);
    int count = 0;
    for(const auto& word : words2){
        if(map.find(word)!=map.end() && map[word] <= 1){
            map[word]--;
        }
    }
    for(const auto& pair : map){
        if(pair.second == 0)
            count++;
    }
    return count;
    
}

int main(int argc, const char * argv[]) {
    std::vector<std::string> words1 = {"leetcode","is","as","amazing"};
    std::vector<std::string> words2 = {"is","leetcode","amazing"};
    std::cout<<countWords(words1, words2)<<std::endl;
    
}
