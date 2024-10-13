#include <iostream>
#include <unordered_map>

//383. Ransom Note
//Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.Each letter in magazine can only be used once in ransomNote.


int timesContainsLetter(const std::string& str,char target){
    std::unordered_map<char, int> map;
    for(const auto& s : str){
        map[s]++;
    }
    
    if(map.find(target) != map.end())
        return map[target];
    return 0;
}

std::unordered_map<char,int> fill(const std::string& str){
    std::unordered_map<char, int> map;
    for(const auto& s : str){
        map[s]++;
    }
    return map;
}

bool canConstruct(std::string ransomNote,std::string magazine){
    if(ransomNote.size() > magazine.size())
        return false;
    std::unordered_map<char, int> secondWordChars = fill(magazine);
    int iters = 0;
    for(int i = 0;i<ransomNote.size();i++){
        if((secondWordChars.find(ransomNote[i]) != secondWordChars.end() && secondWordChars[ransomNote[i]] < timesContainsLetter(ransomNote, ransomNote[i])) || (secondWordChars.find(ransomNote[i]) == secondWordChars.end())){
            return false;
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    std::string ransomNote = "bg";
    std::string magazine = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj";
    std::cout<<canConstruct(ransomNote, magazine);
}
