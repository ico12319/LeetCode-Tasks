#include <iostream>

//2923. Find Champion I
//There are n teams numbered from 0 to n - 1 in a tournament.Given a 0-indexed 2D boolean matrix grid of size n * n. For all i, j that 0 <= i, j <= n - 1 and i != j team i is stronger than team j if grid[i][j] == 1, otherwise, team j is stronger than team i.Team a will be the champion of the tournament if there is no team b that is stronger than team a.Return the team that will be the champion of the tournament.

void dfs(std::vector<std::vector<int>>& adj_matrix,int src,std::vector<bool>& visited){
    visited[src] = true;
    for(int i = 0;i<adj_matrix[src].size();i++){
        if(adj_matrix[src][i] && !visited[i])
            dfs(adj_matrix, i, visited);
    }
}

int find_champion(std::vector<std::vector<int>>& grid){
    std::vector<bool> visied(grid.size(),false);
    for(int i = 0;i<grid.size();i++){
        if(!visied[i]){
            std::vector<bool> visited_by_node(grid.size(),false);
            dfs(grid, i, visited_by_node);
            auto it = std::find(visited_by_node.begin(), visited_by_node.end(), false);
            if(it == visited_by_node.end())
                return i;
            visied[i] = true;
        }
    }
    return -1;
}


int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> grid = {{0,1},{0,0}};
    std::cout<<find_champion(grid)<<std::endl;
}
