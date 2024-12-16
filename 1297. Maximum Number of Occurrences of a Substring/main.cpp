#include <iostream>
#include <queue>

//1297. Maximum Number of Occurrences of a Substring
//Given a string s, return the maximum number of occurrences of any substring under the following rules:The number of unique characters in the substring must be less than or equal to maxLetters.The substring size must be between minSize and maxSize inclusive.

struct compare{
    bool operator()(const std::pair<std::string,int>& p1,const std::pair<std::string,int>& p2)const{
        return p1.second < p2.second;
    }
};


int max_freq(std::string& s,int max_letters,int min_size,int max_size){
    std::unordered_map<char,int> freq;
    std::unordered_map<std::string,int> substr_freq;
    size_t left_ptr = 0;
    size_t right_ptr = 0;
    freq[s[left_ptr]]++;
    while(true){
        size_t curr_window_size = (right_ptr - left_ptr) + 1;
        if(curr_window_size < min_size && freq.size() <= max_letters){
            right_ptr++;
            if(right_ptr >= s.size()) break;
            freq[s[right_ptr]]++;
        }
        else if(curr_window_size == min_size && freq.size() <= max_letters){
            substr_freq[s.substr(left_ptr,curr_window_size)]++;
            freq[s[left_ptr]]--;
            if(freq[s[left_ptr]] == 0) freq.erase(s[left_ptr]);
            left_ptr++;
        }
        else if(freq.size() > max_letters){
            freq[s[left_ptr]]--;
            if(freq[s[left_ptr]] == 0) freq.erase(s[left_ptr]);
            left_ptr++;
        }
    }
    if(substr_freq.empty()) return 0;
    std::vector<std::pair<std::string,int>> temp(substr_freq.begin(),substr_freq.end());
    std::priority_queue<std::pair<std::string,int>,std::vector<std::pair<std::string,int>>,compare> pq(temp.begin(),temp.end());
    return pq.top().second;
}

int main(int argc, const char * argv[]) {
    std::string s = "abcabababacabcabc";
    int max_letters = 3;
    int min_size = 3;
    int max_size = 10;
    std::cout<<max_freq(s, max_letters, min_size, max_size)<<std::endl;;
}
