#include <iostream>

//1254. Number of Closed Islands
//Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.Return the number of closed islands.


void dfs(std::vector<std::vector<int>>& grid,std::vector<std::vector<bool>>& visited,std::vector<std::vector<int>>& directions,int x,int y){
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited[x][y] || grid[x][y])
        return;
    visited[x][y] = true;
    for(const auto& direction : directions){
        auto new_x = x + direction[0];
        auto new_y = y + direction[1];
        dfs(grid, visited, directions, new_x, new_y);
    }
}


int closed_islands(std::vector<std::vector<int>>& grid){
    std::vector<std::vector<bool>> visited(grid.size(),std::vector<bool>(grid[0].size(),false));
    std::vector<std::vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    
    for(int i = 0;i<grid.size();i++){
        for(int j = 0;j<grid[0].size();j++){
            if(!visited[i][j] && (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1) && !grid[i][j])
                dfs(grid, visited, directions, i, j);
        }
    }
    
    int sub_islands = 0;
    for(int i = 1;i<grid.size() - 1;i++){
        for(int j = 1;j<grid[i].size() - 1;j++){
            if(!visited[i][j] && !grid[i][j]){
                dfs(grid, visited, directions, i, j);
                sub_islands++;
            }
        }
    }
    return sub_islands;
    
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    std::cout<<closed_islands(grid)<<std::endl;
}
