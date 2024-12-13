#include <iostream>
#include <queue>

//451. Sort Characters By Frequency
//Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.Return the sorted string. If there are multiple answers, return any of them.

struct pair_comparator{
    bool operator()(const std::pair<int,int>& p1,const std::pair<int, int>& p2) const{
        return p1.second < p2.second;
    }
};

std::string frequency_sort(std::string& s){
    std::unordered_map<char, int> freq;
    std::string res;
    for(const auto& el : s)
        freq[el]++;
    std::vector<std::pair<char,int>> temp(freq.begin(),freq.end());
    std::priority_queue<std::pair<char,int>,std::vector<std::pair<char,int>>,pair_comparator> pq(temp.begin(),temp.end());
    while(!pq.empty()){
        res.push_back(pq.top().first);
        freq[pq.top().first]--;
        if(freq[pq.top().first] == 0){
            freq.erase(pq.top().first);
            pq.pop();
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    std::string s = "Aabb";
    std::cout<<frequency_sort(s)<<std::endl;
}
