#include <iostream>
#include <queue>

//2285. Maximum Total Importance of Roads
//You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.Return the maximum total importance of all roads possible after assigning the values optimally.

bool comparator(std::pair<int,std::vector<int>>& p1,std::pair<int,std::vector<int>>& p2){
    return p1.second.size() > p2.second.size();
}


std::vector<std::pair<int,std::vector<int>>> edge_sort(const std::vector<std::vector<int>>& edges){
    std::unordered_map<int,std::vector<int>> map;
    for(const auto& edge : edges){
        auto from = edge[0];
        auto to = edge[1];
        
        map[from].push_back(to);
        map[to].push_back(from);
    }
    
    std::vector<std::pair<int,std::vector<int>>> res(map.begin(),map.end());
    std::sort(res.begin(), res.end(), comparator);
    return res;
}


long long maximum_importance(int n,std::vector<std::vector<int>>& roads){
    auto sorted = edge_sort(roads);
    int maximum_importance = n;
    std::vector<int> importance_factor(n,0);
    for(int i = 0;i<sorted.size();i++){
        auto index = sorted[i].first;
        importance_factor[index] = maximum_importance;
        maximum_importance--;
    }
    
    long long importance = 0;
    for(int i = 0;i<roads.size();i++)
        importance += (importance_factor[roads[i][0]] + importance_factor[roads[i][1]]);
    return importance;
    
    
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> edges = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    std::cout<< maximum_importance(5, edges);
}
