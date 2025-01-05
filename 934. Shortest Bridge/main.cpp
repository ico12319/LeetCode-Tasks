#include <iostream>
#include <queue>

//934. Shortest Bridge
//You are given an n x n binary matrix grid where 1 represents land and 0 represents water.An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.You may change 0's to 1's to connect the two islands to form one island.Return the smallest number of 0's you must flip to connect the two islands.

void dfs(std::vector<std::vector<int>>& grid,std::vector<std::vector<bool>>& visited,std::vector<std::vector<int>>& directions,int x,int y,std::queue<std::pair<int,int>>& q){
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid.size() || !grid[x][y] || visited[x][y])
        return;
    visited[x][y] = true;
    q.emplace(x,y);
    for(const auto& direction : directions){
        auto new_x = direction[0] + x;
        auto new_y = direction[1] + y;
        dfs(grid, visited, directions, new_x, new_y, q);
    }
}

int shortest_path(std::vector<std::vector<int>>& grid){
    std::vector<std::vector<bool>> visited(grid.size(),std::vector<bool>(grid.size(),false));
    std::queue<std::pair<int,int>> q;
    std::vector<std::vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    bool is_found = false;
    for(int i = 0;i<grid.size();i++){
        for(int j = 0;j<grid.size();j++){
            if(!visited[i][j] && grid[i][j]){
                dfs(grid, visited, directions, i, j, q);
                is_found = true;
                break;
            }
        }
        if(is_found)
            break;
    }
    int min_distance = 0;
    while(!q.empty()){
        auto curr_level_size = q.size();
        for(int i = 0;i<curr_level_size;i++){
            auto curr_vertex_coordinates = q.front();
            q.pop();
            int x = curr_vertex_coordinates.first;
            int y = curr_vertex_coordinates.second;
            for(const auto& direction : directions){
                auto new_x = x + direction[0];
                auto new_y = y + direction[1];
                if(new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid.size() || visited[new_x][new_y])
                    continue;
                if(grid[new_x][new_y])
                    return min_distance;
                q.emplace(new_x,new_y);
                visited[new_x][new_y] = true;
            }
        }
        min_distance++;
    }
    return -1;
}


int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> grid = {{1,1,0},{0,0,0},{0,0,1}};
    std::cout<<shortest_path(grid)<<std::endl;
}
