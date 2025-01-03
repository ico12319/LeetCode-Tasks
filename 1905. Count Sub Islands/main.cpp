#include <iostream>

//1905. Count Sub Islands
//You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.Return the number of islands in grid2 that are considered sub-islands.


void dfs(std::vector<std::vector<int>>& grid,int x,int y,std::vector<std::vector<int>>& directions,std::vector<std::vector<bool>>& visited){
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited[x][y] || !grid[x][y])
        return;
    visited[x][y] = true;
    for(const auto& direction : directions){
        auto new_x = direction[0] + x;
        auto new_y = direction[1] + y;
        dfs(grid, new_x, new_y, directions, visited);
    }
}

void check(std::vector<std::vector<int>>& grid,int x,int y,std::vector<std::vector<int>>& directions,std::vector<std::vector<bool>>& visited1,std::vector<std::vector<bool>>& visited2,int& sub_island){
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited2[x][y] || !grid[x][y])
        return;
    visited2[x][y] = true;
    if(!visited1[x][y])
        sub_island = 0;
    for(const auto& direction : directions){
        auto new_x = direction[0] + x;
        auto new_y = direction[1] + y;
        check(grid, new_x, new_y, directions, visited1,visited2,sub_island);
    }
    
}

int count_sub_islands(std::vector<std::vector<int>>& grid1,std::vector<std::vector<int>>& grid2){
    std::vector<std::vector<bool>> visited(grid1.size(),std::vector<bool>(grid1[0].size(),false));
    std::vector<std::vector<int>> directions = {{1,0},{-1,0},{0,-1},{0,1}};
    for(int i = 0;i<grid1.size();i++){
        for(int j = 0;j<grid1[i].size();j++){
            if(!visited[i][j] && grid1[i][j])
                dfs(grid1, i, j, directions, visited);
        }
    }
    std::vector<std::vector<bool>> visited2(grid2.size(),std::vector<bool>(grid2[0].size(),false));
    int sub_islands = 0;
    for(int i = 0;i<grid2.size();i++){
        for(int j = 0;j<grid2[i].size();j++){
            if(!visited2[i][j] && grid2[i][j]){
                int island = 1;
                check(grid2, i, j, directions, visited, visited2, island);
                sub_islands += island;
                
            }
        }
    }
    return sub_islands;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    std::vector<std::vector<int>> grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
    std::cout<<count_sub_islands(grid1, grid2)<<std::endl;
    
}
