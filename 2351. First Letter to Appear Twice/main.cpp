#include <iostream>
#include <unordered_set>

//2351. First Letter to Appear Twice
//Given a string s consisting of lowercase English letters, return the first letter to appear twice.

char repeatedCharacter(std::string& s){
    std::unordered_set<char> seen;
    for(const auto& symbol : s){
        if(seen.contains(symbol))
            return symbol;
        seen.insert(symbol);
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    std::string str = "abccbaacz";
    std::cout<<repeatedCharacter(str)<<std::endl;
}
