#include <iostream>

//438. Find All Anagrams in a String
//Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

bool anagrams(std::unordered_map<char,int>& map1,std::unordered_map<char,int>& map2,std::string& s){
    for(const auto& symbol : s){
        if(map1[symbol] != map2[symbol]) return false;
    }
    return true;
}

std::vector<size_t> find_anagrams(std::string& s,std::string& p){
    std::unordered_map<char, int> freq;
    std::unordered_map<char, int> freq2;
    std::vector<size_t> res;
    for(const auto& symbol : p)
        freq2[symbol]++;
    size_t left_ptr = 0;
    size_t right_ptr = p.size() - 1;
    for(size_t i = left_ptr;i<p.size();i++)
        freq[s[i]]++;
    while(true){
        if(anagrams(freq, freq2, p))
            res.push_back(left_ptr);
        freq[s[left_ptr]]--;
        left_ptr++;
        if(freq[s[left_ptr]] == 0)
            freq.erase(s[left_ptr]);
        right_ptr++;
        if(right_ptr >= s.size()) break;
        freq[s[right_ptr]]++;
    }
    return res;
}

int main(int argc, const char * argv[]) {
   
    std::string s = "cbaebabacd";
    std::cout<<s.substr(0,3)<<std::endl;
    std::string p = "abc";
    auto res = find_anagrams(s, p);
    for(const auto& el : res)
        std::cout<<el<<" ";
}
