#include <iostream>
#include <deque>

//210. Course Schedule II
//There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

std::vector<std::vector<int>> convert(std::vector<std::vector<int>>& edges,int num_courses){
    std::vector<std::vector<int>> adj(num_courses,std::vector<int>());
    for(const auto& edge : edges){
        auto from = edge[1];
        auto to = edge[0];
        adj[from].push_back(to);
    }
    return adj;
}


bool contains_cycle_helper(std::vector<std::vector<int>>& adj,std::vector<bool>& visited,std::vector<bool>& is_in_stack,int src){
    visited[src] = true;
    is_in_stack[src] = true;
    for(const auto& child : adj[src]){
        if(!visited[child] && contains_cycle_helper(adj, visited, is_in_stack, child))
            return true;
        else if(is_in_stack[child])
            return true;
    }
    is_in_stack[src] = false;
    return false;
}

bool contains_cycle(std::vector<std::vector<int>>& adj){
    std::vector<bool> visited(adj.size(),false);
    std::vector<bool> is_in_stack(adj.size(),false);
    for(int i = 0;i<adj.size();i++){
        if(contains_cycle_helper(adj,visited,is_in_stack,i))
            return true;
    }
    return false;
}

void topological_sort(std::vector<std::vector<int>>& adj,std::vector<int>& sort,std::vector<bool>& visited,int src){
    visited[src] = true;
    for(const auto& child : adj[src]){
        if(!visited[child])
            topological_sort(adj, sort, visited, child);
    }
    sort.push_back(src);
}


std::vector<int> find_order(int num_courses,std::vector<std::vector<int>>& prerequisites){
    auto adj = convert(prerequisites, num_courses);
    if(contains_cycle(adj))
        return {};
    std::vector<int> order;
    std::vector<bool> visited(adj.size(),false);
    for(int i = 0;i<num_courses;i++){
        if(!visited[i])
            topological_sort(adj, order, visited, i);
    }
    std::reverse(order.begin(),order.end());
    return order;
    
}

int main(int argc, const char * argv[]) {
    int num_courses = 4;
    std::vector<std::vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    auto sorted = find_order(num_courses, prerequisites);
    for(const auto& el : sorted)
        std::cout<<el<<" ";
}
