#include <iostream>
#include <queue>

//290. Word Pattern
//Given a pattern and a string s, find if s follows the same pattern.Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:Each letter in pattern maps to exactly one unique word in s.Each unique word in s maps to exactly one letter in pattern.No two letters map to the same word, and no two words map to the same letter.

bool word_pattern(std::string& pattern,std::string& s){
    std::string temp;
    s+=' ';
    std::vector<std::string> parsed;
    for(const auto& el : s){
        if(el != ' ')
            temp+=el;
        else{
            parsed.push_back(temp);
            temp.clear();
        }
    }
    
    if(pattern.size() != parsed.size()) return false;
    std::unordered_map<char,std::string> map1;
    std::unordered_map<std::string, char> map2;
    for(int i = 0;i<pattern.size();i++){
        if(map1.contains(pattern[i]) && map1[pattern[i]] != parsed[i])
            return false;
        if(map2.contains(parsed[i]) && map2[parsed[i]] != pattern[i])
            return false;
        map1[pattern[i]] = parsed[i];
        map2[parsed[i]] = pattern[i];
    }
    return true;
}



int main(int argc, const char * argv[]) {
    std::string pattern = "abba";
    std::string s = "dog dog dog dog";
    std::cout<<word_pattern(pattern, s);
}
