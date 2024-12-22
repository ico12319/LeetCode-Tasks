#include <iostream>

//2924. Find Champion II
//There are n teams numbered from 0 to n - 1 in a tournament; each team is also a node in a DAG.You are given the integer n and a 0-indexed 2D integer array edges of length m representing the DAG, where edges[i] = [ui, vi] indicates that there is a directed edge from team ui to team vi in the graph.A directed edge from a to b in the graph means that team a is stronger than team b and team b is weaker than team a.Team a will be the champion of the tournament if there is no team b that is stronger than team a.Return the team that will be the champion of the tournament if there is a unique champion, otherwise, return -1.

void dfs(std::vector<std::vector<int>>& adj,std::vector<bool>& visited,int src){
    visited[src] = true;
    for(const auto& neighbour : adj[src]){
        if(!visited[neighbour])
            dfs(adj, visited, neighbour);
    }
}

std::vector<std::vector<int>> convert(std::vector<std::vector<int>>& edges,int n){
    std::vector<std::vector<int>> adj(n,std::vector<int>());
    for(const auto& edge : edges)
        adj[edge[0]].push_back(edge[1]);
    return adj;
}

int find_champion(int n,std::vector<std::vector<int>>& edges){
    auto adj = convert(edges, n);
    std::vector<bool> visited(n,false);
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            std::vector<bool> visited_by_vertex(n,false); // we should find a node from where it is possbile to visit all other nodes
            dfs(adj, visited_by_vertex, i);
            auto it = std::find(visited_by_vertex.begin(), visited_by_vertex.end(), false);
            if(it == visited_by_vertex.end())
                return i;
            visited[i] = true;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int n = 4;
    std::vector<std::vector<int>> edges = {{0,2},{1,3},{1,2}};
    std::cout<<find_champion(n, edges)<<std::endl;
}
