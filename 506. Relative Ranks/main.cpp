#include <iostream>

//506. Relative Ranks
//You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
    std::vector<int> original(score.begin(),score.end());
    std::sort(score.begin(),score.end(),std::greater<int>());
   
    
    std::unordered_map<int, std::string> mappedValues;
    if(!score.empty()) mappedValues[score[0]] = "Golden medal";
    if(score.size() > 1) mappedValues[score[1]] = "Silver medal";
    if(score.size() > 2) mappedValues[score[2]] = "Bronze medal";
    for(int i = 3;i<score.size();i++)
        mappedValues[score[i]] = std::to_string(i + 1);
    
    std::vector<std::string> res;
    for(int i = 0;i<original.size();i++)
        res.push_back((mappedValues[original[i]]));
    
    return res;
    
}

int main(int argc, const char * argv[]) {
    std::vector<int> score = {10,3,8,9,4};
    std::vector<std::string> res = findRelativeRanks(score);
    for(const auto& el : res)
        std::cout<<el<<" ";
}
