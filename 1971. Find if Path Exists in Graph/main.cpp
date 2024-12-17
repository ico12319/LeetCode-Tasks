#include <iostream>
#include <set>
#include <queue>

//1971. Find if Path Exists in Graph
//There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.You want to determine if there is a valid path that exists from vertex source to vertex destination.Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

std::vector<std::vector<int>> make_adjecancy_list(std::vector<std::vector<int>>& edges){
    int max_node = 0;
    for(const auto& edge : edges)
        max_node = std::max({max_node,edge[0],edge[1]});
    int size = max_node + 1;
    std::vector<std::vector<int>> adjecancy_list(size);
    for(const auto& edge : edges){
        int u = edge[0];
        int v = edge[1];
        
        adjecancy_list[u].push_back(v);
        adjecancy_list[v].push_back(u);
    }
    return adjecancy_list;
}

bool exsisting_path(std::vector<std::vector<int>>& graph,int src,int destination){
    graph = make_adjecancy_list(graph);
    std::queue<size_t> q;
    std::vector<bool> visited(graph.size(),false);
    q.push(src);
    
    while(!q.empty()){
        size_t curr_node = q.front();
        q.pop();
        
        if(curr_node == destination) return true;
        
        for(const auto& neighbour : graph[curr_node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    return false;
    
}


int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> graph = {{0,1},{1,2},{2,0},{3,5}};
    
    std::cout<<exsisting_path(graph, 0, 3)<<std::endl;
}
