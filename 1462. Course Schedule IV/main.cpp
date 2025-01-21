#include <iostream>

//1462. Course Schedule IV
//There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

std::vector<std::vector<int>> convert(std::vector<std::vector<int>>& edges,int n){
    std::vector<std::vector<int>> adj(n,std::vector<int>());
    for(const auto& edge : edges){
        auto from = edge[0];
        auto to = edge[1];
        
        adj[from].push_back(to);
    }
    return adj;
}


void dfs(std::vector<std::vector<int>>& adj,std::vector<bool>& visited,int src){
    visited[src] = true;
    for(const auto& child : adj[src]){
        if(!visited[child])
            dfs(adj, visited, child);
    }
}

std::vector<bool> check_if_prerequisites(int num_courses,std::vector<std::vector<int>>& edges,std::vector<std::vector<int>>& queries){
    auto adj = convert(edges, num_courses);
    std::vector<std::vector<bool>> is_reachable(num_courses,std::vector<bool>(num_courses,false));
    std::vector<bool> visited(num_courses,false);
    for(int i = 0;i<num_courses;i++){
        if(!visited[i]){
            dfs(adj, is_reachable[i], i);
        }
    }
    std::vector<bool> check(queries.size(),false);
    int index = 0;
    for(const auto& query : queries){
        auto arr_index = query[0];
        auto possible_reachable_index = query[1];
        
        if(!is_reachable[arr_index][possible_reachable_index]){
            check[index++] = false;
            continue;
        }
        check[index++] = true;
    }
    return check;
}



int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> edges = {{2,3},{2,1},{0,3},{0,1}};
    std::vector<std::vector<int>> queries = {{0,1},{0,3},{2,3},{3,0},{2,0},{0,2}};
    int num_courses = 4;
    auto check = check_if_prerequisites(4, edges, queries);
}
