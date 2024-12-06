#include <iostream>

//567. Permutation in String
//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.In other words, return true if one of s1's permutations is the substring of s2.

bool equal_maps(std::unordered_map<char,int>& map1,std::unordered_map<char,int>& map2,const std::string& criteria){
    for(const auto& symbol : criteria){
        if(map1[symbol] != map2[symbol]) return false;
    }
    return true;
}

bool check_inclusion(std::string& s1,std::string& s2){
    if (s1.size() > s2.size()) return false;
    
    std::unordered_map<char, int> freq;
    size_t left_ptr = 0;
    size_t right_ptr = s1.size() - 1;
    for(size_t i = left_ptr;i<s1.size();i++)
        freq[s2[i]]++;
    std::unordered_map<char, int> freq2;
    for(const auto& el : s1)
        freq2[el]++;
    
    while(true){
        if(equal_maps(freq, freq2, s1))
            return true;
        freq[s2[left_ptr]]--;
        if(freq[s2[left_ptr]] == 0) freq.erase(s2[left_ptr]);
        left_ptr++;
        right_ptr++;
        if(right_ptr >= s2.size()) break;
        freq[s2[right_ptr]]++;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    std::string s1 = "dinitrophenylhydrazine";
    std::string s2 = "dimethylhydrazine";
    std::cout<<check_inclusion(s1,s2)<<std::endl;
}
