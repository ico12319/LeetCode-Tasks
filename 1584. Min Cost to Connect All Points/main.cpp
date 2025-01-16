#include <iostream>
#include <queue>

//1584. Min Cost to Connect All Points
//You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

struct prim_utills{
    int curr_vertex;
    int weight;
    
    bool operator<(const prim_utills& other) const{
        return weight > other.weight;
    }
};

std::vector<std::vector<std::pair<int,int>>> convert(const std::vector<std::vector<int>>& points){
    std::vector<std::vector<std::pair<int,int>>> adj(points.size(),std::vector<std::pair<int,int>>());
    for(int i = 0;i<points.size();i++){
        auto from = i;
        for(int  j = 0;j<points.size();j++){
            auto to = j;
            if(i != j){
                auto weight = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                adj[from].emplace_back(to,weight);
            }
        }
    }
    return adj;
}

int total_cost(const std::vector<std::vector<int>>& points){
    auto adj = convert(points);
    std::vector<bool> visited(points.size(),false);
    int cost = 0;
    std::priority_queue<prim_utills> pq;
    int start = 0;
    pq.push({start,0});
    int found_edges = 0;
    while(found_edges != points.size()){
        auto vertex = pq.top().curr_vertex;
        auto weight = pq.top().weight;
        pq.pop();
        
        if(visited[vertex]) continue;
        
        cost+=weight;
        found_edges++;
        
        visited[vertex] = true;
        
        for(const auto& child : adj[vertex]){
            if(!visited[child.first])
                pq.push({child.first,child.second});
        }
    }
    return cost;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    std::cout<<total_cost(points)<<std::endl;
}
