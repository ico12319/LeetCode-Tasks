#include <iostream>
#include <queue>

//743. Network Delay Time
//You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

struct dijkstra_helper{
    int vertex;
    int weight;
    
    bool operator<(const dijkstra_helper& other) const{
        return weight > other.weight;
    }
};


std::vector<std::vector<std::pair<int,int>>> convert(std::vector<std::vector<int>>& times,int n){
    std::vector<std::vector<std::pair<int,int>>> adj(n,std::vector<std::pair<int, int>>());
    for(const auto& edge : times){
        auto from = edge[0] - 1;
        auto to = edge[1] - 1;
        auto weight = edge[2];
        adj[from].emplace_back(to,weight);
    }
    return adj;
}

int find_max(std::vector<int>& distances){
    int max = INT_MIN;
    for(int i = 0;i<distances.size();i++)
        max = std::max(distances[i], max);
    return max;
}

int newtwork_delay_time(std::vector<std::vector<int>>& times,int n,int k){
    std::vector<int> distances(n,INT_MAX);
    auto adj = convert(times, n);
    std::priority_queue<dijkstra_helper> pq;
    std::vector<bool> visited(n,false);
    pq.push({k - 1,0});
    distances[k - 1] = 0;
    int max = INT_MIN;
    while(!pq.empty()){
        auto curr_vertex = pq.top().vertex;
        auto curr_weight = pq.top().weight;
        pq.pop();
        for(const auto& child : adj[curr_vertex]){
            if(child.second + curr_weight < distances[child.first]){
                distances[child.first] = child.second + curr_weight;
                pq.push({child.first,child.second + curr_weight});
            }
        }
        visited[curr_vertex] = true;
    }
    auto it = std::find(visited.begin(), visited.end(), false);
    return (it == visited.end()) ?  find_max(distances) : -1;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> times = {{1,2,1},{2,3,2},{1,3,4}};
    int n = 3;
    int k = 1;
    std::cout<<newtwork_delay_time(times, n, k)<<std::endl;
}
