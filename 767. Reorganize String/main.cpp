#include <iostream>
#include <queue>

//767. Reorganize String
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.Return any possible rearrangement of s or return "" if not possible.

struct pair_comparator{
    bool operator()(const std::pair<char,int>& p1,const std::pair<char,int>& p2) const{
        return p1.second < p2.second;
    }
};

std::priority_queue<std::pair<char,int>,std::vector<std::pair<char,int>>,pair_comparator> parse(const std::string& str){
    std::unordered_map<char, int> map;
    for(const auto& symbol : str)
        map[symbol]++;
    std::vector<std::pair<char,int>> temp(map.begin(),map.end());
    std::priority_queue<std::pair<char,int>,std::vector<std::pair<char,int>>,pair_comparator> pq(temp.begin(),temp.end());
    return pq;
}

std::string reorganize(const std::string& str){
    if(str.empty()) return " ";
    std::string res;
    auto pq = parse(str);
    std::queue<std::pair<char,int>> idle;
    while(!pq.empty() || !idle.empty()){
        if(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            res.push_back(curr.first);
            if(!idle.empty()){
                pq.push(idle.front());
                idle.pop();
            }
            if(curr.second - 1 != 0)
                idle.push({curr.first,curr.second - 1});
        }
        else
            return "";
    }
    return res;
}

int main(int argc, const char * argv[]) {
    std::string str = "baaba";
    auto res = reorganize(str);
    std::cout<<res<<std::endl;
}
