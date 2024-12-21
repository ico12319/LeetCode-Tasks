#include <iostream>

//207. Course Schedule
//There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.Return true if you can finish all courses. Otherwise, return false.

std::vector<std::vector<int>> turn_into_adjecancy(std::vector<std::vector<int>>& edges,int num_courses){
    std::vector<std::vector<int>> adj(num_courses,std::vector<int>());
    for(const auto& edge : edges)
        adj[edge[0]].push_back(edge[1]);
    return adj;
}

bool has_cycle_rec(std::vector<std::vector<int>>& adj,std::vector<bool>& visited,std::vector<bool>& is_in_stack,int src){
    visited[src] = true;
    is_in_stack[src] = true;
    for(const auto& neighbour : adj[src]){
        if(!visited[neighbour] && has_cycle_rec(adj, visited, is_in_stack, neighbour))
            return true;
        else if(is_in_stack[neighbour])
            return true;
    }
    is_in_stack[src] = false;
    return false;
}

bool has_cycle(std::vector<std::vector<int>>& edges,int num_courses){
    std::vector<std::vector<int>> adj = turn_into_adjecancy(edges, num_courses);
    std::vector<bool> visited(num_courses,false);
    std::vector<bool> is_in_stack(num_courses,false);
    for(int i = 0;i<num_courses;i++){
        if(!visited[i]){
            if(has_cycle_rec(adj, visited, is_in_stack, i))
                return false;
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    
    std::vector<std::vector<int>> edges = {{1,0}};
    std::cout<<has_cycle(edges, 2)<<std::endl;
}
