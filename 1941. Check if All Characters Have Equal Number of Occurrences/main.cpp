#include <iostream>
#include <queue>

//1941. Check if All Characters Have Equal Number of Occurrences
//Given a string s, return true if s is a good string, or false otherwise.A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

struct max_heap_pair_compare{
    bool operator()(const std::pair<char, int>& p1, const std::pair<char,int>& p2) const{
        return p1.second < p2.second;
    }
};

struct min_heap_pair_compare{
    bool operator()(const std::pair<char, int>& p1, const std::pair<char,int>& p2) const{
        return p1.second > p2.second;
    }
};

bool are_occurences_equal(const std::string& s){
    std::unordered_map<char,int> freq;
    for(const auto& symbol : s)
        freq[symbol]++;
    std::vector<std::pair<int,int>> temp(freq.begin(),freq.end());
    std::priority_queue<std::pair<char,int>,std::vector<std::pair<char,int>>,max_heap_pair_compare> max_heap(temp.begin(),temp.end());
    std::priority_queue<std::pair<char,int>,std::vector<std::pair<char,int>>,min_heap_pair_compare> min_heap(temp.begin(),temp.end());
    
    return max_heap.top().second == min_heap.top().second;
}

int main(int argc, const char * argv[]) {
    std::string s = "aaabb";
    std::cout<<are_occurences_equal(s)<<std::endl;
}
