#include <iostream>

//2658. Maximum Number of Fish in a Grid
//You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:A land cell if grid[r][c] = 0, or A water cell containing grid[r][c] fish, if grid[r][c] > 0.A fisher can start at any water cell (r, c) and can do the following operations any number of times:Catch all the fish at cell (r, c), or Move to any adjacent water cell.Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

void dfs(std::vector<std::vector<int>>& grid,int x,int y,std::vector<std::vector<bool>>& visited,std::vector<std::vector<int>>& directions,int& sum){
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0 || visited[x][y])
        return;
    visited[x][y] = true;
    sum += grid[x][y];
    for(const auto& direction : directions){
        auto new_x = direction[0] + x;
        auto new_y = direction[1] + y;
        dfs(grid, new_x, new_y, visited, directions,sum);
    }
}

int find_max_fish(std::vector<std::vector<int>>& grid){
    std::vector<std::vector<bool>> visited(grid.size(),std::vector<bool>(grid[0].size(),false));
    std::vector<std::vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int max_fishes = 0;
    for(int i = 0;i<grid.size();i++){
        for(int j = 0;j<grid[0].size();j++){
            if(!visited[i][j] && grid[i][j] != 0){
                int curr_sum = 0;
                dfs(grid, i, j, visited, directions, curr_sum);
                max_fishes = std::max(curr_sum, max_fishes);
            }
        }
    }
    return max_fishes;
}


int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> grid = {{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
    std::cout<<find_max_fish(grid)<<std::endl;
}
