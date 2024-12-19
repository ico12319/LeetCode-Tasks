#include <iostream>

//1791. Find Center of Star Graph
//There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

int find_center(std::vector<std::vector<int>>& edges){
    size_t n = edges.size() + 1;
    std::vector<int> in_edges(n,0);
    for(const auto& edge : edges){
        int from = edge[0];
        int to = edge[1];
        in_edges[from - 1]++;
        in_edges[to - 1]++;
    }
    
    for(int i = 0;i<n;i++){
        if(in_edges[i] == n - 1)
            return i + 1;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> edges = {{1,2},{2,3},{4,2}};
    std::cout<<find_center(edges)<<std::endl;
}
