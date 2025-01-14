#include <iostream>

//1319. Number of Operations to Make Network Connected
//There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

std::vector<std::vector<int>> convert(std::vector<std::vector<int>>& edges,int n){
    std::vector<std::vector<int>> adj(n,std::vector<int>());
    for(const auto& edge : edges){
        auto from = edge[0];
        auto to = edge[1];
        
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    return adj;
}


void dfs(std::vector<std::vector<int>>& adj,std::vector<bool>& visited,int src){
    visited[src] = true;
    for(const auto& child : adj[src]){
        if(!visited[child])
            dfs(adj, visited, child);
    }
}


int make_connected(int n,std::vector<std::vector<int>>& edges){
    if(edges.size() < n - 1)
        return -1;
    
    auto adj = convert(edges, n);
    std::vector<bool> visited(n,false);
    int joined_sets = 0;
    for(int i = 0;i<adj.size();i++){
        if(!visited[i]){
            joined_sets++;
            dfs(adj,visited, i);
        }
    }
    return joined_sets - 1;
}



int main(int argc, const char * argv[]) {
    
}
