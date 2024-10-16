#include <iostream>
//3016. Minimum Number of Pushes to Type Word II
//You are given a string word containing lowercase English letters.Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
//Return the minimum number of pushes needed to type word after remapping the keys.

void determineFrequence(std::vector<int>& freq,std::string& word){
    const size_t wordLen = word.length();
    for(int i = 0;i<wordLen;i++)
        freq[word[i] - 'a']++;
}

void makeZeros(std::vector<int>& v){
    const size_t size = v.size();
    for(int i = 0;i<size;i++)
        v[i] = 0;
}

int minimumPushes(std::string& word){
    std::vector<int> letterFrequency(26);
    makeZeros(letterFrequency);
    determineFrequence(letterFrequency, word);
    std::sort(letterFrequency.begin(),letterFrequency.end(),std::greater<int>());
    int pushes = 0;
    for(int i = 0;i<26;i++){
        if(i < 8)
            pushes+=letterFrequency[i];
        else if(i < 16)
            pushes+=letterFrequency[i]*2;
        else if(i < 24)
            pushes+=letterFrequency[i]*3;
        else
            pushes+=letterFrequency[i]*4;
    }
    return pushes;
    
}

int main(int argc, const char * argv[]) {
    std::string word = "abcde";
    std::cout<<minimumPushes(word)<<std::endl;
}
