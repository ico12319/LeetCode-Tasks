#include <iostream>
#include <queue>

//886. Possible Bipartition
//We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

std::vector<std::vector<int>> turn_into_adjecancy(std::vector<std::vector<int>>& edges,int n){
    std::vector<std::vector<int>> adj(n,std::vector<int>());
    for(const auto& edge : edges){
        int from = edge[0] - 1;
        int to = edge[1] - 1;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    return adj;
}


bool possible_bipartition(int n, std::vector<std::vector<int>>& dislikes) {
    std::vector<std::vector<int>> adj = turn_into_adjecancy(dislikes, n);
    std::vector<int> colors(n,-1);
    std::vector<bool> visited(n,false);
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            std::queue<int> q;
            q.push(i);
            visited[i] = true;
            colors[i] = 1;
            while(!q.empty()){
                int curr_vertex = q.front();
                q.pop();
                
                for(const auto& neighbour : adj[curr_vertex]){
                    if(!visited[neighbour] && colors[neighbour] == -1){
                        visited[neighbour] = true;
                        q.push(neighbour);
                        colors[neighbour] = 1 - colors[curr_vertex];
                    }
                    else if(colors[neighbour] == colors[curr_vertex])
                        return false;
                }
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> edges = {{1,2},{1,3},{2,3}};
    std::cout<<possible_bipartition(3, edges)<<std::endl;
    
}
