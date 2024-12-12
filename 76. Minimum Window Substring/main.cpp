#include <iostream>

//76. Minimum Window Substring
//Given two strings s and t of lengths m and n respectively, return the minimum windowsubstringof s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".The testcases will be generated such that the answer is unique.

bool contains_all(std::unordered_map<char, int>& map1,std::string& t,std::unordered_map<char,int>& map2){
    for(const auto& pair : map2){
        if(map1[pair.first] < pair.second)
            return false;
    }
    return true;
}

std::string min_window(std::string& s,std::string& t){
    std::string min_str;
    size_t min_size = INT_MAX;
    size_t left_ptr = 0;
    size_t right_ptr = 0;
    size_t min_start = 0;
    std::unordered_map<char, int> freq;
    freq[s[left_ptr]]++;
    std::unordered_map<char, int> to_compare;
    for(const auto& s : t)
        to_compare[s]++;
    std::string temp;
    while(true){
        size_t curr_window_size = (right_ptr - left_ptr) + 1;
        if(contains_all(freq, t, to_compare)){
            if(min_size > curr_window_size){
                min_size = curr_window_size;
                min_start = left_ptr;
            }
            freq[s[left_ptr]]--;
            left_ptr++;
        }
        else{
            right_ptr++;
            freq[s[right_ptr]]++;
            if(right_ptr >= s.size()) break;
        }
    }
    return min_size != INT_MAX ? s.substr(min_start,min_size) : "";
}

int main(int argc, const char * argv[]) {
    std::string s = "aaaaaaaaaaaabbbbbcdd";
    std::string t = "abcdd";
    std::cout<<min_window(s, t)<<std::endl;
}
