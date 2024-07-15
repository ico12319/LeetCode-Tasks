#include <iostream>
#include <stack>

// 20. Valid Parentheses
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.


bool isOpeningBracket(char ch){
    return ch == '(' || ch == '{' || ch == '[';
}

bool isClosingBracket(char ch){
    return ch == ')' || ch == '}' || ch == ']';
}


bool areMatchingBrackets(char s1,char s2){
    return (s1 == '(' && s2 == ')') || (s1 == '{' && s2 == '}') || (s1 == '[' && s2 == ']');
}

bool isValidParentheses(const std::string str){
    std::stack<char> stack;
    size_t strSize = str.length();
    
    if(strSize <= 1)
        return false;
    
    for(int i = 0;i<strSize;i++){
        if(isOpeningBracket(str[i]))
            stack.push(str[i]);
        
        else if(isClosingBracket(str[i])){
            if(stack.size() == 0)
                return false;
            
            char curr = stack.top();
            if(areMatchingBrackets(curr, str[i]) && stack.size() > 0)
                stack.pop();
            else
                return false;
        }
    }
    return (stack.size() == 0);
}

int main(int argc, const char * argv[]) {
   
    std::string str = "[({({})})]";
    std::cout<<isValidParentheses(str)<<std::endl;
    
    std::string str2 = "([})";
    std::cout<<isValidParentheses(str2)<<std::endl;
    
}
