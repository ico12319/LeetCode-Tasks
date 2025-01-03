#include <iostream>
#include <queue>

//1926. Nearest Exit from Entrance in Maze
//You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

bool is_exit(std::vector<std::vector<char>>& grid,int x,int y,std::vector<int>& entrance){
    return (y == 0 || y == grid[0].size() - 1 || x == 0 || x == grid.size() - 1) && !(x == entrance[0] && y==entrance[1]);
}

int bfs(std::vector<std::vector<char>>& grid,int x,int y,std::vector<std::vector<int>>& distances,std::vector<int>& entrance){
    std::vector<std::vector<bool>> visited(grid.size(),std::vector<bool>(grid[0].size(),false));
    std::queue<std::tuple<int,int,int>> q;
    q.push({x,y,0});
    visited[x][y] = true;
    while(!q.empty()){
        auto [x,y,dist] = q.front();
        q.pop();
        if(is_exit(grid, x, y,entrance))
            return dist;
        for(const auto& distance : distances){
            auto new_x = distance[0] + x;
            auto new_y = distance[1] + y;
            if(new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size() && grid[new_x][new_y] == '.' && !visited[new_x][new_y]){
                q.push({new_x,new_y,dist + 1});
                visited[new_x][new_y] = true;
            }
        }
    }
    return -1;
}


int nearest_exit(std::vector<std::vector<char>>& maze,std::vector<int>& entrance){
    std::vector<std::vector<bool>> visited(maze.size(),std::vector<bool>(maze[0].size(),false));
    std::vector<std::vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    return bfs(maze, entrance[0], entrance[1], directions,entrance);
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<char>> maze = {{'+','+','+'},{'.','.','.'},{'+','+','+'}};
    std::vector<int> entrance = {1,0};
    std::cout<<nearest_exit(maze, entrance);
    
}
