#include <iostream>
#include <queue>


//3112. Minimum Time to Visit Disappearing Nodes
//There is an undirected graph of n nodes. You are given a 2D array edges, where edges[i] = [ui, vi, lengthi] describes an edge between node ui and node vi with a traversal time of lengthi units.Additionally, you are given an array disappear, where disappear[i] denotes the time when the node i disappears from the graph and you won't be able to visit it.Note that the graph might be disconnected and might contain multiple edges.Return the array answer, with answer[i] denoting the minimum units of time required to reach node i from node 0. If node i is unreachable from node 0 then answer[i] is -1.

std::vector<std::vector<std::pair<int,int>>> convert(int n,std::vector<std::vector<int>>& edges){
    std::vector<std::vector<std::pair<int,int>>> adj(n,std::vector<std::pair<int,int>>());
    for(const auto& edge : edges){
        auto from = edge[0];
        auto to = edge[1];
        auto weight = edge[2];
        
        adj[from].emplace_back(to,weight);
        adj[to].emplace_back(from,weight);
    }
    return adj;
}

struct dijkstra_utills{
    int curr_vertex;
    int distance;
    
    bool operator<(const dijkstra_utills& other) const{
        return distance > other.distance;
    }
};

std::vector<int> minimum_time_to_visit_disappearing_nodes(int n,std::vector<int>& disappear,std::vector<std::vector<int>>& edges){
    auto adj = convert(n, edges);
    int start = 0;
    std::priority_queue<dijkstra_utills> pq;
    pq.push({start,0});
    std::vector<int> answer(n,INT_MAX);
    std::vector<bool> removed(n,false);
    std::vector<bool> visited(n,false);
    answer[start] = 0;
    while(!pq.empty()){
        auto curr_vertex = pq.top().curr_vertex;
        auto curr_distance = pq.top().distance;
        pq.pop();
        if(visited[curr_vertex])
            continue;
        visited[curr_vertex] = true;
        if(answer[curr_vertex] >= disappear[curr_vertex]){
            removed[curr_vertex] = true;
            answer[curr_vertex] = -1;
            continue;
        }
        for(const auto& child : adj[curr_vertex]){
            if(!removed[child.first] && curr_distance + child.second < answer[child.first]){
                pq.push({child.first,child.second + curr_distance});
                answer[child.first] = child.second + curr_distance;
             }
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> edges = {{0,1,2},{1,2,1},{0,2,4}};
    std::vector<int> disappear = {1,1,5};
    auto min_time = minimum_time_to_visit_disappearing_nodes(3, disappear, edges);
    for(const auto& el : min_time)
        std::cout<<el<<" ";
    std::cout<<std::endl;
}
