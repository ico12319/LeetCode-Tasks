#include <iostream>

//692. Top K Frequent Words
//Given an array of strings words and an integer k, return the k most frequent strings.Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

std::unordered_map<std::string, int> fillMap(std::vector<std::string>& words){
    std::unordered_map<std::string, int> wordsOccur;
    for(const auto& word : words)
        wordsOccur[word]++;
    return wordsOccur;
}


bool cmp(std::pair<std::string,int>& p1,std::pair<std::string,int>& p2){
    if(p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}

std::vector<std::string> topKFrequent(std::vector<std::string>& words,int k){
    std::unordered_map<std::string, int> wordsOccur = fillMap(words);
    std::vector<std::pair<std::string,int>> pairs(wordsOccur.begin(),wordsOccur.end());
    std::sort(pairs.begin(), pairs.end(), cmp);
    
    std::vector<std::string> topK;
    for(int i = 0;i<k;i++)
        topK.push_back(pairs[i].first);
    

    return topK;
}


int main(int argc, const char * argv[]) {
    std::vector<std::string> words = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    std::vector<std::string> topK = topKFrequent(words, 4);
    for(const auto& el : topK)
        std::cout<<el<<" ";
}
