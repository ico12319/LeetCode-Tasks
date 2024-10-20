#include <iostream>

//1021. Remove Outermost Parentheses
//A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

bool isOpeningBracket(char b){
    return b=='(';
}

bool isClosingBracket(char b){
    return b == ')';
}

std::string removeOuterParantheses(std::string& s){
    std::string result;
    int operation = 0;
    const size_t size = s.length();
    for(int i = 0;i<size;i++){
        if(isOpeningBracket(s[i])){
            operation++;
            if(operation != 1)
                result.push_back(s[i]);
        }
        else if(isClosingBracket(s[i])){
            operation--;
            if(operation == 0)
                continue;
            result.push_back(s[i]);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::string s = "()()";
    std::cout<<removeOuterParantheses(s)<<std::endl;
}
