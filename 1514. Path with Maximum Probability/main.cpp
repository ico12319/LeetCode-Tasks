#include <iostream>
#include <queue>

//1514. Path with Maximum Probability
//You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

struct dijkstra_utills{
    int curr_vertex;
    double weight;
    
    bool operator<(const dijkstra_utills& other) const{
        return weight < other.weight;
    }
};

std::vector<std::vector<std::pair<int,double>>> convert(std::vector<std::vector<int>>& edges,int n,std::vector<double>& succ_prob){
    std::vector<std::vector<std::pair<int,double>>> adj(n,std::vector<std::pair<int,double>>());
    for(int i = 0;i<n;i++){
        auto from = edges[i][0];
        auto to = edges[i][1];
        auto weight = succ_prob[i];
        adj[from].emplace_back(to,weight);
        adj[to].emplace_back(from,weight);
    }
    return adj;
}


double max_probabilty(int n,std::vector<std::vector<int>>& edges,std::vector<double>& succ_prob,int start_node,int end_node){
    auto adj = convert(edges, n, succ_prob);
    std::priority_queue<dijkstra_utills> pq;
    std::vector<double> probabilities(n,INT_MIN);
    std::vector<bool> visited(n,false);
    probabilities[start_node] = 1.0;
    pq.push({start_node,1.0});
    while(!pq.empty()){
        auto curr_vertex = pq.top().curr_vertex;
        auto curr_chance = pq.top().weight;
        pq.pop();
        if(visited[curr_vertex])
            continue;
        visited[curr_vertex] = true;
        for(const auto& child : adj[curr_vertex]){
            if(child.second * curr_chance > probabilities[child.first]){
                probabilities[child.first] = child.second * curr_chance;
                pq.push({child.first,child.second * curr_chance});
            }
        }
    }
    return probabilities[end_node] == INT_MIN ? 0 : probabilities[end_node];
    
}
int main(int argc, const char * argv[]) {
    int n = 3;
    std::vector<std::vector<int>> edges = {{0,1},{1,2},{0,2}};
    std::vector<double> succ_prob = {0.5,0.5,0.2};
    int start = 0;
    int end = 2;
    std::cout<<max_probabilty(n, edges, succ_prob, start, end)<<std::endl;
}
