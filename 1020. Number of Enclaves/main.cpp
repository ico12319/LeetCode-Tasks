#include <iostream>


void dfs(std::vector<std::vector<int>>& grid,std::vector<std::vector<bool>>& visited,int x,int y,int& connected_components,std::vector<std::vector<int>>& directions,bool& flag){
    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited[x][y] || !grid[x][y]){
        return;
    }
    if(x == grid.size() - 1 || x == 0 || y == grid[0].size() - 1 || y == 0){
        flag = true;
        connected_components = 0;
    }
    visited[x][y] = true;
    if(!flag)
        connected_components++;
    for(const auto& direction : directions){
        auto new_x = direction[0] + x;
        auto new_y = direction[1] + y;
        dfs(grid, visited, new_x, new_y, connected_components, directions,flag);
    }
}

int num_enclaves(std::vector<std::vector<int>>& grid){
    std::vector<std::vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    std::vector<std::vector<bool>>
    visited(grid.size(),std::vector<bool>(grid[0].size(),false));
    int count = 0;
    for(int i = 0;i<grid.size();i++){
        for(int j = 0;j<grid[i].size();j++){
            if(!visited[i][j] && grid[i][j]){
                int connected_components = 0;
                bool flag = false;
                dfs(grid, visited, i, j, connected_components, directions, flag);
                count+=connected_components;
            }
        }
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    
    std::cout<<num_enclaves(grid)<<std::endl;
    
}
