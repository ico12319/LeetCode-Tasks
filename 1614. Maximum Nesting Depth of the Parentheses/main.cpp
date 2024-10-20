#include <iostream>
#include <stack>

//1614. Maximum Nesting Depth of the Parentheses
//Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

bool isOpeningBracket(char b){
    return b == '(';
}

bool isClosingBracket(char b){
    return b == ')';
}


int maxDepth(std::string& s){
    const size_t size = s.length();
    std::stack<char> brackets;
    int maxDepth = 0;
    for(int i = 0;i<size;i++){
        if(isOpeningBracket(s[i])){
            brackets.push(s[i]);
            if(brackets.size() > maxDepth)
                maxDepth = brackets.size();
        }
        else if(isClosingBracket(s[i]))
            brackets.pop();
    }
    return maxDepth;
}

int main(int argc, const char * argv[]) {
    std::string s = "()(())((()()))";
    std::cout<<maxDepth(s)<<std::endl;
}
