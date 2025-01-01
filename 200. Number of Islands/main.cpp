#include <iostream>

//200. Number of Islands
//Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

void dfs(std::vector<std::vector<char>>& grid,std::vector<std::vector<bool>>& visited,int x,int y,std::vector<std::vector<int>>& distances){
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited[x][y] || grid[x][y] == '0')
        return;
    visited[x][y] = true;
    for(const auto& distance : distances){
        auto new_x = distance[0] + x;
        auto new_y = distance[1] + y;
        dfs(grid, visited, new_x, new_y, distances);
    }
}

int number_of_islands(std::vector<std::vector<char>>& grid){
    std::vector<std::vector<bool>> visited(grid.size(),std::vector<bool>(grid[0].size(),false));
    std::vector<std::vector<int>> distances = {{-1,0},{1,0},{0,-1},{0,1}};
    auto count = 0;
    for(int i = 0;i<grid.size();i++){
        for(int j = 0;j<grid[i].size();j++){
            if(!visited[i][j] && grid[i][j] == '1'){
                count++;
                dfs(grid, visited, i, j, distances);
                
            }
        }
    }
    return count;
    
}



int main(int argc, const char * argv[]) {
    std::vector<std::vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    std::cout<<number_of_islands(grid)<<std::endl;
}
