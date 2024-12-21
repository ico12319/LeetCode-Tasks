#include <iostream>
#include <queue>

//785. Is Graph Bipartite?
//There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:There are no self-edges (graph[u] does not contain u).There are no parallel edges (graph[u] does not contain duplicate values).If v is in graph[u], then u is in graph[v] (the graph is undirected).The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.Return true if and only if it is bipartite.

bool is_graph_bipartite(std::vector<std::vector<int>>& graph){
    std::vector<int> color(graph.size(),-1);
    for(int i = 0;i<graph.size();i++){
        if(color[i] == -1){
            std::queue<int> q;
            q.push(i);
            while(!q.empty()){
                int curr_vertex = q.front();
                q.pop();
                for(const auto& neighbour : graph[curr_vertex]){
                    if(color[neighbour] == -1){
                        color[neighbour] = 1 - color[curr_vertex];
                        q.push(neighbour);
                    }
                    else if(color[neighbour] == color[curr_vertex])
                        return false;
                }
            }
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    std::cout<<is_graph_bipartite(graph)<<std::endl;
}
