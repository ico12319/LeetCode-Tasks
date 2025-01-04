#include <iostream>
#include <unordered_set>

//2685. Count the Number of Complete Components
//You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.Return the number of complete connected components of the graph.A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.A connected component is said to be complete if there exists an edge between every pair of its vertices.

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


void dfs(std::vector<std::vector<int>>& adj,std::vector<bool>& visited,int src,std::vector<int>& components){
    visited[src] = true;
    components.push_back(src);
    for(const auto& child : adj[src]){
        if(!visited[child])
            dfs(adj, visited, child, components);
    }
}

int count_complete_components(std::vector<std::vector<int>>& edges,int n){
    std::vector<bool> visited(n,false);
    auto adj = convert(edges, n);
    int count = 0;
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            std::vector<int> components;
            dfs(adj, visited, i, components);
            bool flag = true;
            for(int i = 0;i<components.size();i++){
                if(adj[components[i]].size() != components.size() - 1)
                    flag = false;
            }
            if(flag)
                count++;
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    
    std::vector<std::vector<int>> edges = {{0,1},{0,2},{1,2},{3,4},{3,5}};
    std::cout<<count_complete_components(edges, 6)<<std::endl;
}
