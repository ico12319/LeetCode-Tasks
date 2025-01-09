#include <iostream>
#include <queue>

//1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
//There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

struct dijkstra_utills{
    int curr_vertex;
    int distance;
    
    bool operator<(const dijkstra_utills& other) const{
        return distance > other.distance;
    }
};

std::vector<std::vector<std::pair<int,int>>> convert(std::vector<std::vector<int>>& edges,int n){
    std::vector<std::vector<std::pair<int,int>>> adj(n,std::vector<std::pair<int,int>>());
    for(const auto& edge : edges){
        auto from = edge[0];
        auto to = edge[1];
        auto distance = edge[2];
        
        adj[from].emplace_back(to,distance);
        adj[to].emplace_back(from,distance);
    }
    return adj;
}

std::vector<int> fill_shortest_distances(std::vector<std::vector<std::pair<int,int>>>& adj,int start,int stopper){
    std::vector<bool> visited(adj.size(),false);
    std::vector<int> distances(adj.size(),stopper + 1);
    std::priority_queue<dijkstra_utills> pq;
    pq.push({start,0});
    distances[start] = 0;
    while(!pq.empty()){
        auto curr_vertex = pq.top().curr_vertex;
        auto curr_distance = pq.top().distance;
        pq.pop();
        
        if(visited[curr_vertex])
            continue;
        visited[curr_vertex] = true;
        
        for(const auto& child : adj[curr_vertex]){
            if(child.second + curr_distance < distances[child.first]){
                distances[child.first] = child.first;
                distances[child.first] = child.second + curr_distance;
                pq.push({child.first,child.second + curr_distance});
            }
        }
    }
    return distances;
}

int find_the_city(int n,std::vector<std::vector<int>>& edges,int distance_threshold){
    auto adj = convert(edges, n);
    int max = INT_MIN;
    int min_cities = INT_MAX;
    for(int i = 0;i<n;i++){
        auto curr_shortest_paths = fill_shortest_distances(adj, i, distance_threshold);
        int count = 0;
        for(int i = 0;i<curr_shortest_paths.size();i++){
            if(curr_shortest_paths[i] != 0 && curr_shortest_paths[i] <= distance_threshold)
                count++;
        }
        if(min_cities >= count){
            min_cities = count;
            max = std::max(max, i);
        }
    }
    return max;
}


int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> edges = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    int n = 5;
    std::cout<<find_the_city(n, edges, 2)<<std::endl;
}
