#include <iostream>
#include <queue>

//1859. Sorting the Sentence
//A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

struct compare{
    bool operator()(const std::pair<std::string, int>& p1,const std::pair<std::string, int>& p2) const{
        return p1.second > p2.second;
    }
};

bool is_digit(char s){
    return s >= '0' && s <= '9';
}

std::string sort_sentence(std::string& s){
    std::vector<std::pair<std::string, int>> word_to_index;
    std::string word;
    for(const auto& symbol : s){
        if(is_digit(symbol)){
            word_to_index .push_back(std::make_pair(word,symbol - '0'));
            word.clear();
            continue;
        }
        if(symbol != ' ')
            word+=symbol;
    }
    
    std::priority_queue<std::pair<std::string,int>, std::vector<std::pair<std::string, int>>,compare> pq(word_to_index.begin(),word_to_index.end());
    std::string res;
    while(!pq.empty()){
        res+=pq.top().first;
        //res+=' ';
        pq.pop();
        if(pq.size() != 0)
            res+=' ';
    }
    return res;
    
    
}

int main(int argc, const char * argv[]) {
    std::string s = "z1 z2 z3";
    auto sorted = sort_sentence(s);
    std::cout<<sorted<<std::endl;
}
