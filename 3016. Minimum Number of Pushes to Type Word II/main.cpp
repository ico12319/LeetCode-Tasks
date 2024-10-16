#include <iostream>



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
