#include <iostream>


//2192. All Ancestors of a Node in a Directed Acyclic Graph
//You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.A node u is an ancestor of another node v if u can reach v via a set of edges.

std::vector<std::vector<int>> convert(std::vector<std::vector<int>>& edges,int n){
    std::vector<std::vector<int>> adj(n,std::vector<int>());
    for(const auto& edge : edges){
        auto from = edge[1];
        auto to = edge[0];
        adj[from].push_back(to);
    }
    return adj;
}

void topological_sort(std::vector<std::vector<int>>& adj,std::vector<bool>& visited,int src,int start,std::vector<int>& child_list){
    visited[src] = true;
    for(const auto& child : adj[src]){
        if(!visited[child])
            topological_sort(adj, visited, child, start,child_list);
    }
    if(src != start)
        child_list.push_back(src);
}

std::vector<std::vector<int>> get_ancestors(int n,std::vector<std::vector<int>>& edges){
    auto adj = convert(edges, n);
    std::vector<std::vector<int>> ancestors_list;
    for(int i = 0;i<n;i++){
        std::vector<bool> visited(n,false);
        std::vector<int> child_list;
        topological_sort(adj, visited, i, i, child_list);
        std::sort(child_list.begin(),child_list.end());
        ancestors_list.push_back(child_list);
    }
    return ancestors_list;
}


int main(int argc, const char * argv[]) {
    int n = 8;
    std::vector<std::vector<int>> edge_list = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    auto list = get_ancestors(n, edge_list);
    for(const auto& l : list){
        for(const auto& el : l)
            std::cout<<el<<" ";
        std::cout<<std::endl;
    }
}
