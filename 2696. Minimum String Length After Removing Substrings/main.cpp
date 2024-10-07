#include <iostream>
#include <stack>

//2696. Minimum String Length After Removing Substrings
//You are given a string s consisting only of uppercase English letters.You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.Return the minimum possible length of the resulting string that you can obtain.

int minLength(const std::string& str){
    const size_t size = str.length();
    std::stack<char> letters;
    
    for(const auto& ch : str){
        if(!letters.empty() && ((ch == 'B' && letters.top() == 'A') || (ch == 'D' && letters.top() == 'C'))){
            letters.pop();
        }
        else
            letters.push(ch);
    }
    return letters.size();
}

int main(int argc, const char * argv[]) {
    std::string str = "ABFCACDB";
    std::cout<<minLength(str)<<std::endl;
    
}
