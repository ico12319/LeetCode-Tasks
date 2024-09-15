#include <iostream>

//844. Backspace String Compare
//Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
//Note that after backspacing an empty text, the text will continue empty.



std::string removeBackSpace(const std::string& str){
    std::string res;
    size_t size = str.length();
    int index = 0;
    while(index < size){
        if(res.empty() || str[index] != '#'){
            if(str[index] != '#'){
                res.push_back(str[index]);
            }
        }
        else{
            res.pop_back();
        }
        index++;
    }
    return res;
}


bool backSpaceCompare(const std::string& s,const std::string& t){
    std::string res1 = removeBackSpace(s);
    std::string res2 = removeBackSpace(t);
    return res1 == res2;
}

int main(int argc, const char * argv[]) {
    std::string str = "ab#c";
    std::string str2 = "ad#c";
    std::cout<<backSpaceCompare(str, str2)<<std::endl;
    
    std::string str3 = "y#fo##f";
    std::string result = removeBackSpace(str3);
    std::cout<<result<<std::endl;
}
