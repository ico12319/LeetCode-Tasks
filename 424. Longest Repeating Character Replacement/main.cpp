#include <iostream>

//424. Longest Repeating Character Replacement
//You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.Return the length of the longest substring containing the same letter you can get after performing the above operations.

char get_max_freq_key(std::unordered_map<char, int>& map){
    int max = INT_MIN;
    char key = 'a';
    for(const auto& pair : map){
        if(pair.second > max){
            max = pair.second;
            key = pair.first;
        }
    }
    return key;
}

size_t character_replacement(std::string& s,int k){
    std::unordered_map<char, int> freq;
    size_t left_ptr = 0;
    size_t right_ptr = 0;
    size_t max_size = 0;
    freq[s[left_ptr]]++;
    while(true){
        size_t curr_window_size = (right_ptr - left_ptr) + 1;
        auto most_frequent_key = get_max_freq_key(freq);
        auto most_frequent = freq[most_frequent_key];
        if(curr_window_size - most_frequent <= k){
            right_ptr++;
            freq[s[right_ptr]]++;
            max_size = std::max(max_size, curr_window_size);
            if(right_ptr >= s.size()) break;
        }
        else{
            freq[s[left_ptr]]--;
            left_ptr++;
        }
    }
    return max_size;
}

int main(int argc, const char * argv[]) {
    std::string s = "ABAB";
    int k = 0;
    std::cout<<character_replacement(s, k)<<std::endl;
}
