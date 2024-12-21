#include <iostream>
#include <queue>

//1311. Get Watched Videos by Your Friends
//There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest.

struct compare{
    bool operator()(const std::pair<std::string, int>& p1,const std::pair<std::string, int>& p2) const{
        if(p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second > p2.second;
    }
};

auto watched_videos_by_friends(std::vector<std::vector<std::string>>& watchedVideos, std::vector<std::vector<int>>& friends, int id, int level){
    std::vector<bool> visited(friends.size(),false);
    std::queue<int> q;
    std::vector<int> k_th_level;
    int distance = 0;
    q.push(id);
    visited[id] = true;
    while(!q.empty()){
        auto curr_level_size = q.size();
        std::vector<int> curr_level;
        for(int i = 0;i<curr_level_size;i++){
            int curr_vertex = q.front();
            q.pop();
            curr_level.push_back(curr_vertex);
            for(const auto& neighbour : friends[curr_vertex]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        if(distance == level){
            k_th_level = curr_level;
            break;
        }
        distance++;
    }
    std::unordered_map<std::string, int> freq;
    while(!k_th_level.empty()){
        auto index = k_th_level.back();
        std::vector<std::string> searched = watchedVideos[index];
        for(const auto& str : searched)
            freq[str]++;
        k_th_level.pop_back();
    }
    std::vector<std::pair<std::string,int>> temp(freq.begin(),freq.end());
    std::priority_queue<std::pair<std::string, int>,std::vector<std::pair<std::string,int>>,compare> pq(temp.begin(),temp.end());
    std::vector<std::string> most_watched;
    while(!pq.empty()){
        most_watched.push_back(pq.top().first);
        pq.pop();
    }
    return most_watched;
    
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<std::string>> watched_videos = {{"A","B"},{"C"},{"B","C"},{"D"}};
    std::vector<std::vector<int>> friends = {{1,2},{0,3},{0,3},{1,2}};
    int id = 0;
    int level = 1;
    auto res = watched_videos_by_friends(watched_videos, friends, id, level);
    for(const auto& video : res)
        std::cout<<video<<std::endl;
}
