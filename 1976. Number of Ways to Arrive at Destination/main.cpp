#include <iostream>
#include <queue>


//1976. Number of Ways to Arrive at Destination
//You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

struct dijkstra_utills{
    size_t curr_vertex;
    size_t weight;
    
    bool operator<(const dijkstra_utills& other) const{
        return weight > other.weight;
    }
};

std::vector<std::vector<std::pair<size_t,long long>>> convert(std::vector<std::vector<int>>& roads,int n){
    std::vector<std::vector<std::pair<size_t,long long>>> adj(n,std::vector<std::pair<size_t,long long>>());
    for(const auto& road : roads){
        auto from = road[0];
        auto to = road[1];
        auto weight = road[2];
        
        adj[from].push_back({to,weight});
        adj[to].push_back({from,weight});
    }
    return adj;
}

constexpr long long MOD = 1'000'000'007;

int count_paths(std::vector<std::vector<int>>& roads,int n){
    auto adj = convert(roads, n);
    std::priority_queue<dijkstra_utills> pq;
    std::vector<long long> distances(n,INT_MAX);
    std::vector<long long> count_ways(n,0);
    std::vector<bool> visited(n,false);
    size_t start = 0;
    pq.push({start,0});
    distances[start] = 0;
    count_ways[start] = 1;
    while(!pq.empty()){
        auto curr_node = pq.top().curr_vertex;
        auto weight = pq.top().weight;
        pq.pop();
        if(visited[curr_node])
            continue;
        visited[curr_node] = true;
        for(const auto& child : adj[curr_node]){
            if(child.second + weight < distances[child.first]){
                distances[child.first] = child.second + weight;
                count_ways[child.first] = count_ways[curr_node];
                pq.push({child.first,child.second + weight});
            }
            else if(child.second + weight == distances[child.first])
                count_ways[child.first] += count_ways[curr_node];
        }
    }
    return count_ways[n - 1] % MOD;
}


int main(int argc, const char * argv[]) {
    int n = 7;
    std::vector<std::vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    std::cout<<count_paths(roads, n)<<std::endl;
}
