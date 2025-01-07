#include <iostream>
#include <queue>

//2374. Node With Highest Edge Score
//You are given a directed graph with n nodes labeled from 0 to n - 1, where each node has exactly one outgoing edge.The graph is represented by a given 0-indexed integer array edges of length n, where edges[i] indicates that there is a directed edge from node i to node edges[i].The edge score of a node i is defined as the sum of the labels of all the nodes that have an edge pointing to i.Return the node with the highest edge score. If multiple nodes have the same edge score, return the node with the smallest index.

struct compare{
    bool operator()(const std::pair<int, int>& p1,const std::pair<int,int>& p2) const{
        if(p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second < p2.second;
    }
};

std::vector<std::vector<int>> convert(std::vector<int>& edges){
    std::vector<std::vector<int>> adj(edges.size(),std::vector<int>());
    for(int i = 0;i<edges.size();i++){
        auto from = edges[i];
        auto to = i;
        adj[from].push_back(to);
    }
    return adj;
}

int find_max(std::vector<int>& edges){
    auto adj = convert(edges);
    std::vector<std::pair<int,int>> sums(adj.size(),std::pair<int,int>(-1,0));
    for(int i = 0;i<adj.size();i++){
        for(int j = 0;j<adj[i].size();j++){
            sums[i].second+=adj[i][j];
            sums[i].first = i;
        }
    }
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,compare> pq(sums.begin(),sums.end());
    return pq.top().first;
}


int main(int argc, const char* argv[]) {
    std::vector<int> edges = {1,0,0,0,0,7,7,5};
    std::cout<<find_max(edges)<<std::endl;
    
    

}
