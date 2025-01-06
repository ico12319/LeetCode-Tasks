#include <iostream>
#include <queue>

//787. Cheapest Flights Within K Stops
//There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

std::vector<std::vector<std::pair<int,int>>> convert(std::vector<std::vector<int>>& egdes,int n){
    std::vector<std::vector<std::pair<int,int>>> adj(n,std::vector<std::pair<int,int>>());
    for(const auto& edge : egdes){
        auto from = edge[0];
        auto to = edge[1];
        auto weight = edge[2];
        adj[from].emplace_back(to,weight);
    }
    return adj;
    
}

size_t find_cheapest_price(int n,std::vector<std::vector<int>>& flights,int src,int dst,int k){
    auto adj = convert(flights, n);
    std::queue<std::pair<int,std::pair<int,int>>> q; // stops,node,weight
    std::vector<int> distances(n,INT_MAX);
    q.push({0,{src,0}});
    while(!q.empty()){
        auto curr_node = q.front().second.first;
        auto curr_stop = q.front().first;
        auto curr_distance = q.front().second.second;
        q.pop();
        
        if(curr_stop > k)
            continue;
        for(const auto& child : adj[curr_node]){
            if(child.second + curr_distance < distances[child.first]){
                distances[child.first] = child.second + curr_distance;
                q.push({curr_stop + 1,{child.first,child.second + curr_distance}});
            }
        }
    }
    return distances[dst] == INT_MAX ? -1 : distances[dst];
}
        

int main(int argc, const char * argv[]) {
    int n = 3;
    std::vector<std::vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500},{1,3,600},{2,3,200}};
    int src = 0;
    int dst = 2;
    int k = 0;
    std::cout<<find_cheapest_price(n, flights, src, dst, k)<<std::endl;
}
