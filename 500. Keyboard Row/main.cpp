#include <iostream>

//500. Keyboard Row
//Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.

std::vector<std::string> find_words(std::vector<std::string>& words){
    std::string row1 = "qwertyuiop";
    std::string row2 = "asdfghjkl";
    std::string row3 = "zxcvbnm";
    std::vector<std::string> res;
    
    std::unordered_map<char, int> letter_to_row;
    for(const auto& s : row1)
        letter_to_row[s] = 1;
    for(const auto& s : row2)
        letter_to_row[s] = 2;
    for(const auto& s : row3)
        letter_to_row[s] = 3;
    
    for(const auto& word : words){
        bool is_valid = true;
        char first_letter = std::tolower(word[0]);
        if(!letter_to_row.contains(first_letter)) continue;
        auto curr_row = letter_to_row[first_letter];
        for(const auto& s : word){
            if(!letter_to_row.contains(std::tolower(s)) || letter_to_row[std::tolower(s)] != curr_row){
                is_valid = false;
                break;
            }
        }
        if(is_valid)
            res.push_back(word);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    std::vector<std::string> words = {"Hello","Alaska","Dad","Peace"};
    std::vector<std::string> res = find_words(words);
    for(const auto& word : res)
        std::cout<<word<<" ";
    
}
