#include <iostream>
#include <stack>

//547. Number of Provinces
//There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
//A province is a group of directly or indirectly connected cities and no other cities outside of the group.

void dfs(std::vector<std::vector<int>>& grid,int src,std::vector<bool>& visited){
    visited[src] = true;
    for(int i = 0;i<grid.size();i++){
        if(i != src && grid[src][i] && !visited[i])
            dfs(grid,i , visited);
    }
}

int find_circle_num(std::vector<std::vector<int>>& grid){
    std::vector<bool> visited(grid.size(),false);
    int provinces = 0;
    for(int i = 0;i<grid.size();i++){
        if(!visited[i]){
            dfs(grid, i, visited);
            provinces++;
        }
    }
    return provinces;
}

int main(int argc, const char * argv[]) {
    
    std::vector<std::vector<int>> grid= {{1,0,0},{0,1,0},{0,0,1}};
    std::cout<<find_circle_num(grid)<<std::endl;
}
