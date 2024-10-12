#include <iostream>
#include <stack>

//2000. Reverse Prefix of Word
//Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".Return the resulting string.

bool containsSymbol(const std::string& word,char ch,int& occurIndex){
    const size_t size = word.length();
    for(int i = 0;i<size;i++){
        if(word[i] == ch){
            occurIndex = i;
            return true;
        }
    }
    return false;
}
std::string reversePrefix(std::string& word,char ch){
    int occurIndex = 0;
    if(!containsSymbol(word, ch,occurIndex))
        return word;
    const size_t size = word.length();
    int origIndex = 0;
    std::stack<char> reversedPart;
    for(int i = 0;i<=occurIndex;i++)
        reversedPart.push(word[i]);
    
    std::string res;
    int resIndex = 0;
    while(!reversedPart.empty()){
        res.push_back(reversedPart.top());
        reversedPart.pop();
    }
    
    for(int i = occurIndex + 1;i<size;i++){
        res.push_back(word[i]);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    std::string word = "xyxzxe";
    std::string res = reversePrefix(word, 'z');
    std::cout<<res<<std::endl;
}
