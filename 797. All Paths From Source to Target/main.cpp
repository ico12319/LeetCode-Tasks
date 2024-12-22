#include <iostream>

//797. All Paths From Source to Target
//Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

void dfs(std::vector<std::vector<int>>& adj,std::vector<std::vector<int>>& paths,int src,int end,std::vector<int>& curr_path){
    curr_path.push_back(src);
    
    for(const auto& neighbour : adj[src])
        dfs(adj, paths, neighbour, end, curr_path);
    
    if(curr_path.back() == end)
        paths.push_back(curr_path);
    curr_path.pop_back();
}

std::vector<std::vector<int>> all_paths_source_target(std::vector<std::vector<int>>& graph){
    std::vector<int> curr_path;
    std::vector<std::vector<int>> paths;
    dfs(graph, paths, 0, graph.size() - 1, curr_path);
    return paths;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> adj = {{4,3,1},{3,2,4},{3},{4},{}};
    std::vector<int> curr_path;
    std::vector<std::vector<int>> paths;
    dfs(adj, paths, 0, 4, curr_path);
    for(const auto& path : paths){
        for(const auto& el : path)
            std::cout<<el<<" ";
        std::cout<<std::endl;
    }
}
