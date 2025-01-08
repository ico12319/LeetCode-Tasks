#include <iostream>
#include <queue>

//1376. Time Needed to Inform All Employees
//A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree structure.The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).

struct dijkstra_utills{
    int curr_node;
    int weight;
    
    bool operator<(const dijkstra_utills& other) const{
        return weight > other.weight;
    }
};

std::vector<std::vector<std::pair<int,int>>> convert(int n,std::vector<int>& edges,std::vector<int>& distances){
    std::vector<std::vector<std::pair<int,int>>> adj(n,std::vector<std::pair<int,int>>());
    for(int i = 0;i<n;i++){
        if(edges[i] != -1){
            adj[edges[i]].emplace_back(i,distances[edges[i]]);
        }
    }
    return adj;
}

int num_of_minutes(int n,int head_id,std::vector<int>& manager,std::vector<int>& inform_time){
    auto adj = convert(n, manager, inform_time);
    std::priority_queue<dijkstra_utills> pq;
    pq.push({head_id,0});
    std::vector<int> time(n,INT_MAX);
    std::vector<bool> visited(n,false);
    time[head_id] = 0;
    while(!pq.empty()){
        auto curr_vertex = pq.top().curr_node;
        auto curr_weight = pq.top().weight;
        pq.pop();
        if(visited[curr_vertex]) continue;
        visited[curr_vertex] = true;
        for(const auto& child : adj[curr_vertex]){
            if(child.second + curr_weight < time[child.first]){
                time[child.first] = child.second + curr_weight;
                pq.push({child.first,child.second + curr_weight});
            }
        }
    }
    auto max_el = std::max_element(time.begin(), time.end());
    return *max_el;
}



int main(int argc, const char * argv[]) {
    int n = 7;
    int head_id = 6;
    std::vector<int> manager = {1,2,3,4,5,6,-1};
    std::vector<int> inform_time = {0,6,5,4,3,2,1};
    std::cout<<num_of_minutes(n, head_id, manager, inform_time)<<std::endl;
}
