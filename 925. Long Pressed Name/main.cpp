#include <iostream>

// 925. Long Pressed Name
// Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
//You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

bool isLongPressedName(const std::string& name,const std::string& typed){
    const size_t nameLen = name.length();
    const size_t typedLen = typed.length();
    int index = 0;
    if(name[0]!=typed[0])
        return false;
    
    for(int i = 0;i<typedLen;i++){
        if(name[index] == typed[i])
            index++;
        else if(name[index]!=typed[i] && name[index - 1] != typed[i])
            return false;
    }
    return index == nameLen;
}

int main(int argc, const char * argv[]) {
    std::string name = "alex";
    std::string typed = "aalllleex";
    std::cout<<isLongPressedName(name, typed)<<std::endl;
}
