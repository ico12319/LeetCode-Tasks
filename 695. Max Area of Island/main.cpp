#include <iostream>

//695. Max Area of Island
//You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.The area of an island is the number of cells with a value 1 in the island.Return the maximum area of an island in grid. If there is no island, return 0.

void dfs(std::vector<std::vector<int>>& grid,std::vector<std::vector<bool>>& visited,int x,int y,std::vector<std::vector<int>>& directions,int& area){
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || !grid[x][y] || visited[x][y])
        return;
    visited[x][y] = true;
    area++;
    for(const auto& direction : directions){
        auto new_x = direction[0] + x;
        auto new_y = direction[1] + y;
        dfs(grid, visited, new_x, new_y, directions,area);
    }
}


int max_area_of_islands(std::vector<std::vector<int>>& grid){
    int max_count = 0;
    std::vector<std::vector<bool>> visited(grid.size(),std::vector<bool>(grid[0].size(),false));
    std::vector<std::vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i = 0;i<grid.size();i++){
        for(int j = 0;j<grid[0].size();j++){
            if(!visited[i][j] && grid[i][j]){
                int area = 0;
                dfs(grid, visited, i, j, directions, area);
                max_count = std::max(max_count, area);
            }
        }
    }
    return max_count;
}

int main(int argc, const char * argv[]) {
    
    std::vector<std::vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    std::cout<<max_area_of_islands(grid)<<std::endl;
}
