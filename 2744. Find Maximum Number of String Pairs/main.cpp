#include <iostream>

//2744. Find Maximum Number of String Pairs
//Return the maximum number of pairs that can be formed from the array words.Note that each string can belong in at most one pair.


int max_numbers_of_string_pairs(std::vector<std::string>& words){
    std::unordered_map<std::string, int> freq;
    for(const auto& word : words){
        auto curr_word = word;
        std::sort(curr_word.begin(),curr_word.end());
        freq[curr_word]++;
    }
    auto count = 0;
    for(const auto& pair : freq){
        if(pair.second > 1)
            count++;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    std::vector<std::string> words = {"cd","ac","dc","ca","zz"};
    std::cout<<max_numbers_of_string_pairs(words)<<std::endl;
}
