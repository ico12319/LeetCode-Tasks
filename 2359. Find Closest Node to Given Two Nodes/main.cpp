#include <iostream>
#include <queue>

//2359. Find Closest Node to Given Two Nodes
//You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.You are also given two integers node1 and node2.Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.Note that edges may contain cycles.
struct dijkstra_utills{
    int curr_node;
    int weight;
    
    bool operator<(const dijkstra_utills& other) const{
        return weight > other.weight;
    }
};


std::vector<std::vector<int>> convert(const std::vector<int>& edges){
    std::vector<std::vector<int>> adj(edges.size(),std::vector<int>());
    for(int i = 0;i<edges.size();i++){
        if(edges[i] != -1)
            adj[i].push_back(edges[i]);
    }
    return adj;
}

std::vector<int> dijkstra(std::vector<std::vector<int>>& adj,int src){
    std::queue<dijkstra_utills> q;
    std::vector<bool> visited(adj.size(),false);
    std::vector<int> distances(adj.size(),INT_MAX);
    int distance = 0;
    q.push({src,0});
    distances[src] = 0;
    while(!q.empty()){
        auto curr_node = q.front().curr_node;
        auto curr_weight = q.front().weight;
        distance++;
        q.pop();
        if(visited[curr_node])
            continue;
        visited[curr_node] = true;
        for(const auto& child : adj[curr_node]){
            if(distances[child] > distance){
                distances[child] = distance;
                q.push({child,distance});
            }
        }
    }
    return distances;
}

int closest_meeting_point(std::vector<int>& edges,int node1,int node2){
    auto adj = convert(edges);
    auto distances1 = dijkstra(adj, node1);
    for(const auto& distance : distances1)
        std::cout<<distance<<" ";
    std::cout<<std::endl;
    auto distances2 = dijkstra(adj, node2);
    for(const auto& distance : distances2)
        std::cout<<distance<<" ";
    std::cout<<std::endl;
    int meeting_point = -1;
    int min_max_distance = INT_MAX;
    for(int i = 0;i<distances1.size();i++){
        if(distances1[i] != INT_MAX && distances2[i] != INT_MAX){
            int curr_max = std::max(distances1[i],distances2[i]);
            if(curr_max < min_max_distance){
                min_max_distance = curr_max;
                meeting_point = i;
            }
            else if(curr_max == min_max_distance && i < meeting_point)
                meeting_point = i;
        }
    }
    return meeting_point;
}


int main(int argc, const char * argv[]) {
    std::vector<int> edges = {2,0,0};
    std::cout<<closest_meeting_point(edges, 2,0)<<std::endl;
}
