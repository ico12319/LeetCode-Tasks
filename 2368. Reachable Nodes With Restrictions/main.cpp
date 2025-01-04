#include <iostream>

//2368. Reachable Nodes With Restrictions
//There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.Note that node 0 will not be a restricted node.

std::vector<std::vector<int>> convert(int n,std::vector<std::vector<int>>& edges){
    std::vector<std::vector<int>> adj(n,std::vector<int>());
    for(const auto& edge : edges){
        auto from = edge[0];
        auto to = edge[1];
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    return adj;
}


void dfs(std::vector<std::vector<int>>& adj,std::vector<bool>& visited,int src,int& count){
    visited[src] = true;
    for(const auto& child : adj[src]){
        if(!visited[child]){
            count++;
            dfs(adj, visited, child,count);
        }
    }
}

int reachable_nodes(int n,std::vector<std::vector<int>>& edges,std::vector<int>& restricted){
    std::vector<bool> visited(n,false);
    for(int i = 0;i<restricted.size();i++)
        visited[restricted[i]] = true;
    auto adj = convert(n, edges);
    int count = 1;
    dfs(adj, visited, 0, count);
    return count;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> edges = {{0,1},{0,2},{0,5},{0,4},{3,2},{6,5}};
    std::vector<int> restricted = {4,2,1};
    std::cout<<reachable_nodes(7, edges, restricted)<<std::endl;
}
