#include <iostream>
#include <unordered_set>

//3. Longest Substring Without Repeating Characters
//Given a string s, find the length of the longestsubstring without repeating characters.

size_t length_of_the_longest_substring(const std::string& s){
    std::unordered_set<char> set;
    size_t left_ptr = 0;
    size_t right_ptr = 0;
    size_t max_size = 0;
    while(true){
        size_t curr_window_size = (right_ptr - left_ptr) + 1;
        if(!set.contains(s[right_ptr])){
            set.insert(s[right_ptr]);
            right_ptr++;
            max_size = std::max(max_size,curr_window_size);
            if(right_ptr >= s.size()) break;
        }
        else{
            set.erase(s[left_ptr]);
            left_ptr++;
        }
    }
    return max_size;
}

int main(int argc, const char * argv[]) {
    std::string s = "xxxx";
    std::cout<<length_of_the_longest_substring(s)<<std::endl;
}

