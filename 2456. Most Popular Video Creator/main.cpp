#include <iostream>
#include <queue>

//2456. Most Popular Video Creator
//You are given two string arrays creators and ids, and an integer array views, all of length n. The ith video on a platform was created by creators[i], has an id of ids[i], and has views[i] views.The popularity of a creator is the sum of the number of views on all of the creator's videos. Find the creator with the highest popularity and the id of their most viewed video.If multiple creators have the highest popularity, find all of them.If multiple videos have the highest view count for a creator, find the lexicographically smallest id.Note: It is possible for different videos to have the same id, meaning that ids do not uniquely identify a video. For example, two videos with the same ID are considered as distinct videos with their own viewcount.
//Return a 2D array of strings answer where answer[i] = [creatorsi, idi] means that creatorsi has the highest popularity and idi is the id of their most popular video. The answer can be returned in any order.

struct comparator{
    bool operator()(const std::pair<std::string,int>& p1,const std::pair<std::string,int>& p2) const{
        if(p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second < p2.second;
    }
};

struct comparator2{
    bool operator()(const std::pair<std::string,int>& p1,const std::pair<std::string,int>& p2) const{
        return p1.second < p2.second;
    }
};


std::vector<std::vector<std::string>> mostPopularCreator(std::vector<std::string>& creators, std::vector<std::string>& ids, std::vector<int>& views) {
    std::unordered_map<std::string,std::priority_queue<std::pair<std::string,int>,std::vector<std::pair<std::string,int>>,comparator>> map;
    std::unordered_map<std::string,int> sum_views;
    
    for(int i = 0;i<creators.size();i++){
        sum_views[creators[i]]+=views[i];
        map[creators[i]].push({ids[i],views[i]});
    }
    
    std::vector<std::pair<std::string,int>> temp(sum_views.begin(),sum_views.end());
    std::vector<std::vector<std::string>>res;
    std::priority_queue<std::pair<std::string,int>,std::vector<std::pair<std::string,int>>,comparator2> pq(temp.begin(),temp.end());
    int max_views = pq.top().second;
    while(!pq.empty()){
        if(max_views != pq.top().second)
            break;
        res.push_back({pq.top().first,map[pq.top().first].top().first});
        pq.pop();
    }
    return res;
}

int main(int argc, const char * argv[]) {
    std::vector<std::string> creators = {"alice","alice","alice"};
    std::vector<std::string> ids = {"a","b","c"};
    std::vector<int> views = {1,2,2};
    
    auto res = mostPopularCreator(creators, ids, views);
    for(const auto& creator : res){
        for(const auto& el : creator)
            std::cout<<el<<" ";
        std::cout<<std::endl;
    }
}
