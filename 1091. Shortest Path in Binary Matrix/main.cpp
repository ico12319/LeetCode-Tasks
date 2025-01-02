#include <iostream>
#include <queue>

//1091. Shortest Path in Binary Matrix
//Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:All the visited cells of the path are 0.All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).The length of a clear path is the number of visited cells of this path.

int bfs(std::vector<std::vector<int>>& grid){
    std::vector<std::vector<bool>> visited(grid.size(),std::vector<bool>(grid.size(),false));
    std::vector<std::pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1},{1,-1},{1,1},{-1,1},{-1,-1}};
    size_t n = grid.size();
    std::queue<std::tuple<int,int,int>> q;
    q.push({0,0,1});
    visited[0][0] = true;
    while(!q.empty()){
        auto[x,y,dist] = q.front();
        q.pop();
        if(x == n - 1 && y == n - 1)
            return dist;
        for(const auto& direction : directions){
            auto new_x = direction.first + x;
            auto new_y = direction.second + y;
            
            if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && !grid[new_x][new_y] && !visited[new_x][new_y]){
                q.push({new_x,new_y,dist + 1});
                visited[new_x][new_y] = true;
            }
        }
    }
    return -1;
    
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
    std::cout<<bfs(grid)<<std::endl;
}
