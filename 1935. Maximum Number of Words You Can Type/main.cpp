#include <iostream>
#include <unordered_set>


//1935. Maximum Number of Words You Can Type
//There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.

int can_be_typed_words(const std::string& text,const std::string& broken_letters){
    std::unordered_set<char> prohibited_letres(broken_letters.begin(),broken_letters.end());
    bool flag = true;
    int cnt = 0;
    for(int i = 0;i<text.size();i++){
        if(text[i] != ' '){
            if(prohibited_letres.contains(text[i]))
                flag = false;
        }
        else if(flag)
            cnt++;
        else
            flag = true;
    }
    return flag ? cnt + 1 : cnt;
}

int main(int argc, const char * argv[]) {
    std::string text = "hello world";
    std::string broken_letters = "b";
    std::cout<<can_be_typed_words(text, broken_letters)<<std::endl;
}
