#include <iostream>

//802. Find Eventual Safe States
//There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

bool contains_cycle_helper(std::vector<std::vector<int>>& adj,std::vector<bool>& is_in_stack,std::vector<bool>& visited,int src){
    visited[src] = true;
    is_in_stack[src] = true;
    for(const auto& child : adj[src]){
        if(!visited[child] && contains_cycle_helper(adj, is_in_stack, visited, child))
            return true;
        else if(is_in_stack[child])
            return true;
    }
    is_in_stack[src] = false;
    return false;
}

void extract_nodes(std::vector<std::vector<int>>& adj,std::vector<bool>& visited,std::vector<int>& reversed_topo,int src){
    visited[src] = true;
    for(const auto& child : adj[src]){
        if(!visited[child])
            extract_nodes(adj, visited, reversed_topo, child);
    }
    reversed_topo.push_back(src);
}

std::vector<int> eventual_safe_nodes(std::vector<std::vector<int>>& graph){
    std::vector<bool> visited(graph.size(),false);
    std::vector<bool> is_in_stack(graph.size(),false);
    std::vector<int> topo_sort;
    for(int i = 0;i<graph.size();i++){
        if(contains_cycle_helper(graph, is_in_stack, visited, i)){
            continue;
        }
        else{
            extract_nodes(graph, visited, topo_sort, i);
        }
    }
    return topo_sort;
}


int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    auto topo = eventual_safe_nodes(graph);
    for(const auto& el : topo)
        std::cout<<el<<" ";
    std::cout<<std::endl;
    
    std::vector<int> topo2;
    std::vector<bool> visited(graph.size(),false);
    
    
    
}
